#include <filesystem>
#include <format>
#include <iostream>
#include <vector>

#include "uddf2fit/conversions.hpp"
#include "uddf2fit/dive_stats.hpp"
#include "uddf2fit/fit_writer.hpp"
#include "uddf2fit/uddf_parser.hpp"
#include "uddf2fit/uddf_types.hpp"

// FIT SDK types
#include <fit_profile.hpp>

namespace {

auto extract_waypoints(const uddf2fit::Dive& dive) -> std::vector<uddf2fit::WaypointData> {
    std::vector<uddf2fit::WaypointData> waypoints;
    waypoints.reserve(dive.waypoints.size());

    for (const auto& wp : dive.waypoints) {
        uddf2fit::WaypointData data;
        data.depth = wp.depth;
        data.divetime = wp.divetime;
        data.temperature = wp.temperature;
        waypoints.push_back(data);
    }

    return waypoints;
}

auto extract_gases(const uddf2fit::Dive& dive, const uddf2fit::UddfDocument& doc)
    -> std::vector<uddf2fit::GasMix> {
    std::vector<uddf2fit::GasMix> gases;

    for (const auto& eq : dive.equipment) {
        if (!eq.gas_ref.empty()) {
            if (const auto* gas = doc.find_gas(eq.gas_ref)) {
                uddf2fit::GasMix mix;
                mix.id = gas->id;
                mix.oxygen_percent = uddf2fit::fraction_to_percent(gas->o2_fraction);
                mix.helium_percent = uddf2fit::fraction_to_percent(gas->he_fraction);

                // Avoid duplicates
                bool found = false;
                for (const auto& existing : gases) {
                    if (existing.id == mix.id) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    gases.push_back(mix);
                }
            }
        }
    }

    // Check waypoints for gas switches
    for (const auto& wp : dive.waypoints) {
        if (wp.gas_switch_ref) {
            if (const auto* gas = doc.find_gas(*wp.gas_switch_ref)) {
                uddf2fit::GasMix mix;
                mix.id = gas->id;
                mix.oxygen_percent = uddf2fit::fraction_to_percent(gas->o2_fraction);
                mix.helium_percent = uddf2fit::fraction_to_percent(gas->he_fraction);

                // Avoid duplicates
                bool found = false;
                for (const auto& existing : gases) {
                    if (existing.id == mix.id) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    gases.push_back(mix);
                }
            }
        }
    }

    // Default to air if no gases found
    if (gases.empty()) {
        gases.push_back({.oxygen_percent = 21, .helium_percent = 0, .id = "air"});
    }

    return gases;
}

auto extract_location(const uddf2fit::Dive& dive, const uddf2fit::UddfDocument& doc)
    -> std::optional<uddf2fit::GeoLocation> {
    if (!dive.info_before.divesite_ref) {
        return std::nullopt;
    }

    const auto* site = doc.find_site(*dive.info_before.divesite_ref);
    if (!site) {
        return std::nullopt;
    }

    if (!site->location.latitude || !site->location.longitude) {
        return std::nullopt;
    }

    return uddf2fit::GeoLocation{
        .latitude = *site->location.latitude,
        .longitude = *site->location.longitude
    };
}

void convert_dive(const uddf2fit::Dive& dive,
                  const uddf2fit::UddfDocument& doc,
                  uint32_t dive_number,
                  uint32_t surface_interval,
                  const std::filesystem::path& output_path) {

    // Extract data from UDDF
    auto waypoints = extract_waypoints(dive);
    if (waypoints.empty()) {
        std::cerr << "Dive has no waypoints, skipping\n";
        return;
    }

    auto gases = extract_gases(dive, doc);
    auto location = extract_location(dive, doc);
    auto stats = uddf2fit::calculate_dive_stats(waypoints);

    // Parse datetime
    const auto& datetime_str = dive.info_before.datetime;
    auto start_time = uddf2fit::iso_to_fit_timestamp(datetime_str);
    auto end_time = start_time + static_cast<uint32_t>(stats.bottom_time);

    bool is_multi_gas = gases.size() > 1;

    // Write FIT file
    uddf2fit::DiveFitWriter writer(output_path);
    if (!writer.is_open()) {
        std::cerr << "Failed to open output file: " << output_path << "\n";
        return;
    }

    // Write messages in order
    writer.write_file_id(start_time);
    writer.write_device_info(start_time);
    writer.write_sport();
    writer.write_dive_settings();
    writer.write_dive_gas(gases);

    writer.write_event_timer_start(start_time);

    // Write all record messages
    std::optional<double> prev_depth;
    std::optional<double> prev_time;
    for (const auto& wp : waypoints) {
        auto timestamp = start_time + static_cast<uint32_t>(wp.divetime);

        std::optional<int8_t> temp;
        if (wp.temperature) {
            temp = uddf2fit::kelvin_to_celsius(*wp.temperature);
        }

        std::optional<double> ascent_rate;
        if (prev_depth && prev_time && wp.divetime > *prev_time) {
            double dt = wp.divetime - *prev_time;
            ascent_rate = (*prev_depth - wp.depth) / dt;  // Positive = ascending
        }

        writer.write_record(timestamp, wp.depth, temp, ascent_rate);

        prev_depth = wp.depth;
        prev_time = wp.divetime;
    }

    writer.write_event_timer_stop(end_time);
    writer.write_lap(start_time, end_time, stats, is_multi_gas);
    writer.write_session(start_time, end_time, stats, location, is_multi_gas);

    // Write two dive summaries: one for session, one for lap
    writer.write_dive_summary(end_time, stats, dive_number, surface_interval,
                              FIT_MESG_NUM_SESSION, 0);
    writer.write_dive_summary(end_time, stats, dive_number, surface_interval,
                              FIT_MESG_NUM_LAP, 0);

    writer.write_activity(end_time, static_cast<uint32_t>(stats.bottom_time));

    if (writer.close()) {
        std::cout << "Created: " << output_path.filename() << "\n";
    } else {
        std::cerr << "Failed to close FIT file properly: " << output_path << "\n";
    }
}

} // namespace

auto main(int argc, char* argv[]) -> int {
    if (argc < 2) {
        std::cerr << "Usage: uddf2fit <uddf_file> <output_dir>\n";
        return 1;
    }
    if (argc < 3) {
        std::cerr << "Missing argument: output_dir\n";
        return 1;
    }

    std::filesystem::path uddf_file{argv[1]};
    std::filesystem::path output_dir{argv[2]};

    if (!std::filesystem::exists(uddf_file)) {
        std::cerr << "UDDF file does not exist: " << uddf_file << '\n';
        return 1;
    }
    if (std::filesystem::is_directory(uddf_file)) {
        std::cerr << "UDDF input must be a file, not directory: " << uddf_file << '\n';
        return 1;
    }

    // Load UDDF file
    std::cout << "Loading: " << uddf_file << "\n";
    auto uddf_data = uddf2fit::load_uddf(uddf_file);
    if (!uddf_data) {
        std::cerr << "Failed to parse UDDF file\n";
        return 1;
    }

    // Create output directory
    if (std::filesystem::is_regular_file(output_dir)) {
        std::cerr << "Output directory cannot be a file: " << output_dir << '\n';
        return 1;
    }
    if (!std::filesystem::exists(output_dir)) {
        std::filesystem::create_directories(output_dir);
    }

    // Convert each dive
    uint32_t dive_index = 0;
    uint32_t prev_dive_end = 0;

    auto all_dives = uddf_data->all_dives();
    if (all_dives.empty()) {
        std::cerr << "No dives found in UDDF file\n";
        return 1;
    }

    for (const auto* dive : all_dives) {
        // Calculate surface interval
        uint32_t surface_interval = 0xFFFFFFFF;  // Unknown
        if (prev_dive_end > 0) {
            auto start_time = uddf2fit::iso_to_fit_timestamp(dive->info_before.datetime);
            if (start_time > prev_dive_end) {
                surface_interval = start_time - prev_dive_end;
            }
        }

        // Use dive index as dive number
        uint32_t dive_number = dive_index + 1;

        // Generate output filename
        auto filename = std::format("dive_{:03d}.fit", dive_index);
        auto output_path = output_dir / filename;

        convert_dive(*dive, *uddf_data, dive_number, surface_interval, output_path);

        // Track end time for surface interval calculation
        if (!dive->waypoints.empty()) {
            auto start_time = uddf2fit::iso_to_fit_timestamp(dive->info_before.datetime);
            auto last_divetime = dive->waypoints.back().divetime;
            prev_dive_end = start_time + static_cast<uint32_t>(last_divetime);
        }

        dive_index++;
    }

    std::cout << "Converted " << dive_index << " dive(s)\n";
    return 0;
}
