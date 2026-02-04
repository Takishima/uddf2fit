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

auto extract_dive_settings(const uddf2fit::Dive& dive, const uddf2fit::UddfDocument& doc)
    -> uddf2fit::DiveFitWriter::DiveSettingsData {
    uddf2fit::DiveFitWriter::DiveSettingsData settings;

    // Try to get water density from dive site
    if (dive.info_before.divesite_ref) {
        if (const auto* site = doc.find_site(*dive.info_before.divesite_ref)) {
            if (site->density) {
                settings.water_density = static_cast<float>(*site->density);
                // Determine water type based on density (threshold at 1012.5 kg/m³)
                settings.is_salt_water = (*site->density > 1012.5);
            }
        }
    }

    // Get gradient factors from decomodel if available
    if (doc.deco_model) {
        // Warn if using a non-Bühlmann model (FIT only supports ZHL-16C)
        if (doc.deco_model->model_type == uddf2fit::TissueModelType::RGBM) {
            std::cerr << "Warning: UDDF uses RGBM decompression model, but FIT only supports ZHL-16C. "
                      << "Gradient factors will not be applied.\n";
        } else if (doc.deco_model->model_type == uddf2fit::TissueModelType::VPM) {
            std::cerr << "Warning: UDDF uses VPM decompression model, but FIT only supports ZHL-16C. "
                      << "Gradient factors will not be applied.\n";
        } else if (doc.deco_model->model_type == uddf2fit::TissueModelType::Buehlmann) {
            // Bühlmann model - apply gradient factors
            if (doc.deco_model->gf_low) {
                settings.gf_low = *doc.deco_model->gf_low;
            }
            if (doc.deco_model->gf_high) {
                settings.gf_high = *doc.deco_model->gf_high;
            }
        }
    }

    return settings;
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
    auto dive_settings = extract_dive_settings(dive, doc);
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
    writer.write_dive_settings(dive_settings);
    writer.write_dive_gas(gases);

    writer.write_event_timer_start(start_time);

    // Track CNS/N2 for summary
    uint8_t start_cns = 0;
    uint8_t end_cns = 0;
    uint16_t start_n2 = 0;
    uint16_t end_n2 = 0;
    uint16_t end_otu = 0;
    bool first_waypoint = true;

    // Write all record messages with extended data
    std::optional<double> prev_depth;
    std::optional<double> prev_time;
    for (size_t i = 0; i < dive.waypoints.size(); ++i) {
        const auto& uddf_wp = dive.waypoints[i];
        auto timestamp = start_time + static_cast<uint32_t>(uddf_wp.divetime);

        uddf2fit::DiveFitWriter::RecordData record;
        record.depth = uddf_wp.depth;

        // Temperature (convert from Kelvin to Celsius)
        if (uddf_wp.temperature) {
            record.temperature = uddf2fit::kelvin_to_celsius(*uddf_wp.temperature);
        }

        // Ascent rate
        if (prev_depth && prev_time && uddf_wp.divetime > *prev_time) {
            double dt = uddf_wp.divetime - *prev_time;
            record.ascent_rate = (*prev_depth - uddf_wp.depth) / dt;  // Positive = ascending
        }

        // Heart rate
        if (uddf_wp.heartrate) {
            record.heart_rate = static_cast<uint8_t>(*uddf_wp.heartrate);
        }

        // CNS load (UDDF uses 0-1 fraction, FIT uses 0-100%)
        if (uddf_wp.cns) {
            uint8_t cns_percent = static_cast<uint8_t>(*uddf_wp.cns * 100.0);
            record.cns_load = cns_percent;
            if (first_waypoint) {
                start_cns = cns_percent;
            }
            end_cns = cns_percent;
        }

        // pO2 (prefer measured over calculated for rebreathers)
        if (uddf_wp.measured_po2) {
            record.po2 = *uddf_wp.measured_po2;
        } else if (uddf_wp.calculated_po2) {
            record.po2 = *uddf_wp.calculated_po2;
        }

        // NDL time (no-decompression limit)
        if (uddf_wp.ndl_time) {
            record.ndl_time = static_cast<uint32_t>(*uddf_wp.ndl_time);
        }

        // Deco stop info
        if (uddf_wp.deco_stop) {
            record.next_stop_depth = uddf_wp.deco_stop->depth;
            record.next_stop_time = static_cast<uint32_t>(uddf_wp.deco_stop->duration);
        }

        // OTU tracking (cumulative)
        if (uddf_wp.otu) {
            end_otu = static_cast<uint16_t>(*uddf_wp.otu);
        }

        writer.write_record(timestamp, record);

        prev_depth = uddf_wp.depth;
        prev_time = uddf_wp.divetime;
        first_waypoint = false;
    }

    writer.write_event_timer_stop(end_time);
    writer.write_lap(start_time, end_time, stats, is_multi_gas);
    writer.write_session(start_time, end_time, stats, location, is_multi_gas);

    // Build dive summary data
    // Use the passed dive_number (from CLI --start-number or default)
    uddf2fit::DiveFitWriter::DiveSummaryData summary_data;
    summary_data.dive_number = dive_number;
    summary_data.surface_interval = dive.info_before.surface_interval
        ? static_cast<uint32_t>(*dive.info_before.surface_interval)
        : surface_interval;
    summary_data.start_cns = start_cns;
    summary_data.end_cns = end_cns;
    summary_data.start_n2 = start_n2;
    summary_data.end_n2 = end_n2;
    summary_data.o2_toxicity = end_otu;

    // Write two dive summaries: one for session, one for lap
    writer.write_dive_summary(end_time, stats, summary_data, FIT_MESG_NUM_SESSION, 0);
    writer.write_dive_summary(end_time, stats, summary_data, FIT_MESG_NUM_LAP, 0);

    writer.write_activity(end_time, static_cast<uint32_t>(stats.bottom_time));

    if (writer.close()) {
        std::cout << "Created: " << output_path.filename() << "\n";
    } else {
        std::cerr << "Failed to close FIT file properly: " << output_path << "\n";
    }
}

} // namespace

void print_usage() {
    std::cerr << "Usage: uddf2fit <uddf_file> <output_dir> [options]\n"
              << "\n"
              << "Options:\n"
              << "  -n, --start-number N   Start dive numbering at N (default: 1)\n"
              << "  -h, --help             Show this help message\n";
}

auto main(int argc, char* argv[]) -> int {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    // Parse arguments
    std::filesystem::path uddf_file;
    std::filesystem::path output_dir;
    uint32_t start_dive_number = 1;

    int positional_count = 0;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            print_usage();
            return 0;
        } else if (arg == "-n" || arg == "--start-number") {
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires a number argument\n";
                return 1;
            }
            try {
                start_dive_number = static_cast<uint32_t>(std::stoul(argv[++i]));
            } catch (const std::exception&) {
                std::cerr << "Error: Invalid dive number: " << argv[i] << "\n";
                return 1;
            }
        } else if (arg[0] == '-') {
            std::cerr << "Error: Unknown option: " << arg << "\n";
            print_usage();
            return 1;
        } else {
            // Positional argument
            if (positional_count == 0) {
                uddf_file = arg;
            } else if (positional_count == 1) {
                output_dir = arg;
            } else {
                std::cerr << "Error: Too many arguments\n";
                print_usage();
                return 1;
            }
            ++positional_count;
        }
    }

    if (uddf_file.empty()) {
        std::cerr << "Error: Missing uddf_file argument\n";
        print_usage();
        return 1;
    }
    if (output_dir.empty()) {
        std::cerr << "Error: Missing output_dir argument\n";
        print_usage();
        return 1;
    }

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

        // Use start_dive_number + index as dive number
        uint32_t dive_number = start_dive_number + dive_index;

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
