#ifndef UDDF2FIT_FIT_WRITER_HPP
#define UDDF2FIT_FIT_WRITER_HPP

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <optional>
#include <string>
#include <vector>

#include <garmin_fit_sdk/fit.hpp>
#include <garmin_fit_sdk/fit_encode.hpp>

#include "dive_stats.hpp"

namespace uddf2fit {

struct GasMix {
    uint8_t oxygen_percent;
    uint8_t helium_percent;
    std::string id;  // UDDF mix ID for reference
};

struct GeoLocation {
    double latitude;
    double longitude;
};

class DiveFitWriter {
public:
    explicit DiveFitWriter(const std::filesystem::path& output_path);
    ~DiveFitWriter();

    DiveFitWriter(const DiveFitWriter&) = delete;
    DiveFitWriter& operator=(const DiveFitWriter&) = delete;

    // Write messages in order
    void write_file_id(FIT_DATE_TIME time_created);
    void write_device_info(FIT_DATE_TIME timestamp);
    void write_sport();
    // Dive settings configuration
    struct DiveSettingsData {
        bool is_salt_water = true;
        float water_density = 1025.0f;  // kg/m³
        uint8_t gf_low = 40;            // Gradient factor low %
        uint8_t gf_high = 85;           // Gradient factor high %
    };

    void write_dive_settings(const DiveSettingsData& settings);
    void write_dive_settings();  // Use defaults
    void write_dive_gas(const std::vector<GasMix>& gases);

    void write_event_timer_start(FIT_DATE_TIME timestamp);
    void write_event_gas_switch(FIT_DATE_TIME timestamp, uint8_t gas_index);
    void write_event_timer_stop(FIT_DATE_TIME timestamp);

    // Extended record data for dive waypoints
    struct RecordData {
        double depth{0.0};
        std::optional<int8_t> temperature;
        std::optional<double> ascent_rate;
        std::optional<uint8_t> heart_rate;         // bpm
        std::optional<uint8_t> cns_load;           // 0-100%
        std::optional<uint16_t> n2_load;           // tissue loading %
        std::optional<double> po2;                 // partial pressure O2 (bar)
        std::optional<uint32_t> ndl_time;          // no-deco limit (seconds)
        std::optional<double> next_stop_depth;     // deco stop depth (m)
        std::optional<uint32_t> next_stop_time;    // deco stop time (seconds)
        std::optional<uint32_t> absolute_pressure; // ambient pressure (Pa)
    };

    void write_record(FIT_DATE_TIME timestamp, const RecordData& data);

    // Keep simple overload for backwards compatibility
    void write_record(FIT_DATE_TIME timestamp,
                      double depth,
                      std::optional<int8_t> temperature,
                      std::optional<double> ascent_rate);

    void write_lap(FIT_DATE_TIME start_time,
                   FIT_DATE_TIME end_time,
                   const DiveStatistics& stats,
                   bool is_multi_gas);

    void write_session(FIT_DATE_TIME start_time,
                       FIT_DATE_TIME end_time,
                       const DiveStatistics& stats,
                       const std::optional<GeoLocation>& location,
                       bool is_multi_gas);

    // Extended dive summary data
    struct DiveSummaryData {
        uint32_t dive_number{0};
        uint32_t surface_interval{0};
        uint8_t start_cns{0};      // Starting CNS %
        uint8_t end_cns{0};        // Ending CNS %
        uint16_t start_n2{0};      // Starting N2 tissue loading %
        uint16_t end_n2{0};        // Ending N2 tissue loading %
        uint16_t o2_toxicity{0};   // OTU (Oxygen Toxicity Units)
    };

    void write_dive_summary(FIT_DATE_TIME timestamp,
                            const DiveStatistics& stats,
                            const DiveSummaryData& summary_data,
                            FIT_MESG_NUM reference_mesg,
                            uint16_t reference_index);

    // Keep simple overload for backwards compatibility
    void write_dive_summary(FIT_DATE_TIME timestamp,
                            const DiveStatistics& stats,
                            uint32_t dive_number,
                            uint32_t surface_interval,
                            FIT_MESG_NUM reference_mesg,
                            uint16_t reference_index);

    void write_activity(FIT_DATE_TIME timestamp, uint32_t total_elapsed_time);

    bool close();
    bool is_open() const { return is_open_; }

private:
    std::fstream file_;
    fit::Encode encoder_;
    bool is_open_ = false;
};

} // namespace uddf2fit

#endif // UDDF2FIT_FIT_WRITER_HPP
