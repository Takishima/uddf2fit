#include <filesystem>
#include <format>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "uddf2fit/conversions.hpp"
#include "uddf2fit/dive_stats.hpp"
#include "uddf2fit/fit_writer.hpp"
#include "uddf2fit/load.hpp"

#include <diveType.hxx>
#include <gasdefinitions.hxx>
#include <mixType.hxx>
#include <profiledata.hxx>
#include <repetitiongroupType.hxx>
#include <samplesType.hxx>
#include <siteType.hxx>
#include <waypointType.hxx>

namespace {

auto extract_waypoints(const streit::samplesType& samples) -> std::vector<uddf2fit::WaypointData> {
    std::vector<uddf2fit::WaypointData> waypoints;
    waypoints.reserve(samples.waypoint().size());

    for (const auto& wp : samples.waypoint()) {
        uddf2fit::WaypointData data;
        data.depth = wp.depth();
        data.divetime = wp.divetime();

        if (wp.temperature().present()) {
            data.temperature = wp.temperature().get();
        }

        waypoints.push_back(data);
    }

    return waypoints;
}

auto extract_gases(const streit::diveType& dive,
                   const std::unordered_map<std::string, const streit::mixType*>& gas_definitions)
    -> std::vector<uddf2fit::GasMix> {
    std::vector<uddf2fit::GasMix> gases;

    for (const auto& tankdata : dive.tankdata()) {
        if (!tankdata.link().empty()) {
            const auto& ref = tankdata.link().front().ref();
            if (auto it = gas_definitions.find(std::string{ref}); it != gas_definitions.end()) {
                const auto* mix = it->second;
                uddf2fit::GasMix gas;
                gas.id = std::string{ref};
                gas.oxygen_percent = uddf2fit::fraction_to_percent(mix->o2());
                gas.helium_percent = mix->he().present()
                    ? uddf2fit::fraction_to_percent(mix->he().get())
                    : 0;

                // Avoid duplicates
                bool found = false;
                for (const auto& existing : gases) {
                    if (existing.id == gas.id) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    gases.push_back(gas);
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

auto extract_location(const streit::diveType& dive,
                      const std::unordered_map<std::string, const streit::siteType*>& dive_sites)
    -> std::optional<uddf2fit::GeoLocation> {
    if (dive.informationbeforedive().link().empty()) {
        return std::nullopt;
    }

    const auto& ref = dive.informationbeforedive().link().front().ref();
    auto it = dive_sites.find(std::string{ref});
    if (it == dive_sites.end()) {
        return std::nullopt;
    }

    const auto* site = it->second;
    if (!site->geography().present()) {
        return std::nullopt;
    }

    const auto& geo = site->geography().get();
    if (!geo.latitude().present() || !geo.longitude().present()) {
        return std::nullopt;
    }

    return uddf2fit::GeoLocation{
        .latitude = geo.latitude().get(),
        .longitude = geo.longitude().get()
    };
}

auto get_datetime_string(const streit::diveType& dive) -> std::string {
    const auto& dt = dive.informationbeforedive().datetime();
    return std::format("{:04d}-{:02d}-{:02d}T{:02d}:{:02d}:{:02d}",
                       dt.year(), dt.month(), dt.day(),
                       dt.hours(), dt.minutes(),
                       static_cast<int>(dt.seconds()));
}

void convert_dive(const streit::diveType& dive,
                  const std::unordered_map<std::string, const streit::siteType*>& dive_sites,
                  const std::unordered_map<std::string, const streit::mixType*>& gas_definitions,
                  uint32_t dive_number,
                  uint32_t surface_interval,
                  const std::filesystem::path& output_path) {

    if (!dive.samples().present()) {
        std::cerr << "Dive has no samples, skipping\n";
        return;
    }

    // Extract data from UDDF
    auto waypoints = extract_waypoints(dive.samples().get());
    if (waypoints.empty()) {
        std::cerr << "Dive has no waypoints, skipping\n";
        return;
    }

    auto gases = extract_gases(dive, gas_definitions);
    auto location = extract_location(dive, dive_sites);
    auto stats = uddf2fit::calculate_dive_stats(waypoints);

    // Parse datetime
    auto datetime_str = get_datetime_string(dive);
    auto start_time = uddf2fit::iso_to_fit_timestamp(datetime_str);
    auto end_time = start_time + static_cast<FIT_DATE_TIME>(stats.bottom_time);

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
        auto timestamp = start_time + static_cast<FIT_DATE_TIME>(wp.divetime);

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

    // Build lookup maps
    std::unordered_map<std::string, const streit::siteType*> dive_sites;
    if (uddf_data->divesite().present()) {
        for (const auto& site : uddf_data->divesite()->site()) {
            dive_sites.emplace(std::string{site.id()}, &site);
        }
    }

    std::unordered_map<std::string, const streit::mixType*> gas_definitions;
    if (uddf_data->gasdefinitions().present()) {
        for (const auto& mix : uddf_data->gasdefinitions()->mix()) {
            gas_definitions.emplace(std::string{mix.id()}, &mix);
        }
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
    FIT_DATE_TIME prev_dive_end = 0;

    if (!uddf_data->profiledata().present()) {
        std::cerr << "No profile data in UDDF file\n";
        return 1;
    }

    for (const auto& rep_group : uddf_data->profiledata()->repetitiongroup()) {
        for (const auto& dive : rep_group.dive()) {
            // Calculate surface interval
            uint32_t surface_interval = 0xFFFFFFFF;  // Unknown
            if (prev_dive_end > 0) {
                auto datetime_str = get_datetime_string(dive);
                auto start_time = uddf2fit::iso_to_fit_timestamp(datetime_str);
                if (start_time > prev_dive_end) {
                    surface_interval = start_time - prev_dive_end;
                }
            }

            // Get dive number from UDDF or use index
            uint32_t dive_number = dive_index + 1;
            if (dive.informationbeforedive().divenumber().present()) {
                dive_number = static_cast<uint32_t>(dive.informationbeforedive().divenumber().get());
            }

            // Generate output filename
            auto filename = std::format("dive_{:03d}.fit", dive_index);
            auto output_path = output_dir / filename;

            convert_dive(dive, dive_sites, gas_definitions,
                        dive_number, surface_interval, output_path);

            // Track end time for surface interval calculation
            if (dive.samples().present() && !dive.samples()->waypoint().empty()) {
                auto datetime_str = get_datetime_string(dive);
                auto start_time = uddf2fit::iso_to_fit_timestamp(datetime_str);
                auto last_divetime = dive.samples()->waypoint().back().divetime();
                prev_dive_end = start_time + static_cast<FIT_DATE_TIME>(last_divetime);
            }

            dive_index++;
        }
    }

    std::cout << "Converted " << dive_index << " dive(s)\n";
    return 0;
}
