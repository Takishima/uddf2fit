#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace uddf2fit {

// Gas mixture definition
struct UddfGasMix {
    std::string id;
    double o2_fraction{0.21};      // Oxygen fraction (default air)
    double he_fraction{0.0};       // Helium fraction
    double n2_fraction{0.79};      // Nitrogen fraction (default air)
    std::string name;
};

// Geographic location
struct Location {
    std::optional<double> latitude;
    std::optional<double> longitude;
    std::optional<double> altitude;
};

// Dive site information
struct DiveSite {
    std::string id;
    std::string name;
    Location location;
    std::optional<double> density;  // Water density in kg/m³ (fresh ~1000, salt ~1025)
};

// Decompression stop information
struct DecoStop {
    std::string kind;      // "safety" or "mandatory"
    double depth{0.0};     // Deco stop depth in meters
    double duration{0.0};  // Deco stop duration in seconds
};

// Single waypoint in a dive profile
struct Waypoint {
    double divetime{0.0};                      // Time since dive start (seconds)
    double depth{0.0};                         // Depth in meters
    std::optional<double> temperature;         // Temperature in Kelvin
    std::optional<double> tank_pressure;       // Tank pressure in Pascal
    std::optional<std::string> alarm;          // Alarm type if any
    std::optional<std::string> gas_switch_ref; // Gas switch reference

    // Additional fields supported by FIT
    std::optional<double> heartrate;           // Heart rate in bpm
    std::optional<double> cns;                 // CNS oxygen toxicity (0-1 fraction)
    std::optional<double> otu;                 // Oxygen Toxicity Units
    std::optional<double> calculated_po2;     // Calculated pO2 in bar
    std::optional<double> measured_po2;       // Measured pO2 in bar
    std::optional<double> ndl_time;           // No-decompression limit (seconds)
    std::optional<double> setpo2;             // Rebreather setpoint pO2
    std::optional<DecoStop> deco_stop;        // Current deco stop info
};

// Information collected before the dive
struct InformationBeforeDive {
    std::string datetime;                      // ISO datetime string
    std::optional<std::string> divesite_ref;   // Reference to dive site
    std::optional<double> surface_interval;    // Surface interval in seconds
    std::optional<double> air_temperature;     // Air temperature in Kelvin
    std::optional<uint32_t> dive_number;       // Sequential dive number
    std::optional<double> altitude;            // Altitude in meters
    std::optional<double> surface_pressure;    // Surface pressure in Pascal
};

// Information collected after the dive
struct InformationAfterDive {
    std::optional<double> greatest_depth;      // Max depth in meters
    std::optional<double> average_depth;       // Average depth in meters
    std::optional<double> dive_duration;       // Total dive time in seconds
    std::optional<double> lowest_temperature;  // Min water temp in Kelvin
    std::optional<std::string> notes;          // Dive notes

    // Decompression/physiology data
    std::optional<double> end_cns;             // End CNS % (0-100)
    std::optional<double> end_otu;             // End OTU (Oxygen Toxicity Units)
};

// Equipment configuration for a dive
struct EquipmentUsed {
    std::string gas_ref;                       // Reference to gas mix used
    double tank_volume{0.0};                   // Tank volume in liters
    double tank_pressure_start{0.0};           // Start pressure in Pascal
    double tank_pressure_end{0.0};             // End pressure in Pascal
};

// Complete dive profile
struct Dive {
    std::string id;
    InformationBeforeDive info_before;
    InformationAfterDive info_after;
    std::vector<Waypoint> waypoints;
    std::vector<EquipmentUsed> equipment;
};

// Repetition group containing one or more dives
struct RepetitionGroup {
    std::string id;
    std::vector<Dive> dives;
};

// Complete UDDF document structure
struct UddfDocument {
    std::string version;
    std::vector<UddfGasMix> gases;
    std::vector<DiveSite> dive_sites;
    std::vector<RepetitionGroup> repetition_groups;

    // Convenience method to get all dives flattened
    [[nodiscard]] auto all_dives() const -> std::vector<const Dive*> {
        std::vector<const Dive*> result;
        for (const auto& rg : repetition_groups) {
            for (const auto& dive : rg.dives) {
                result.push_back(&dive);
            }
        }
        return result;
    }

    // Find a gas mix by ID
    [[nodiscard]] auto find_gas(const std::string& id) const -> const UddfGasMix* {
        for (const auto& gas : gases) {
            if (gas.id == id) {
                return &gas;
            }
        }
        return nullptr;
    }

    // Find a dive site by ID
    [[nodiscard]] auto find_site(const std::string& id) const -> const DiveSite* {
        for (const auto& site : dive_sites) {
            if (site.id == id) {
                return &site;
            }
        }
        return nullptr;
    }
};

} // namespace uddf2fit
