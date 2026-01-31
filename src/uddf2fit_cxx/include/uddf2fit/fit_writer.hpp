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
    void write_dive_settings();
    void write_dive_gas(const std::vector<GasMix>& gases);

    void write_event_timer_start(FIT_DATE_TIME timestamp);
    void write_event_gas_switch(FIT_DATE_TIME timestamp, uint8_t gas_index);
    void write_event_timer_stop(FIT_DATE_TIME timestamp);

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
