#ifndef UDDF2FIT_DIVE_STATS_HPP
#define UDDF2FIT_DIVE_STATS_HPP

#include <cstddef>
#include <optional>
#include <vector>

namespace uddf2fit {

struct DiveStatistics {
    double avg_depth = 0.0;
    double max_depth = 0.0;
    size_t max_depth_sample_index = 0;

    std::optional<double> avg_temperature;  // Celsius
    std::optional<double> min_temperature;
    std::optional<double> max_temperature;

    double bottom_time = 0.0;     // seconds (last divetime)
    double descent_time = 0.0;    // time to reach max depth
    double ascent_time = 0.0;     // time from max depth to end

    double avg_ascent_rate = 0.0;   // m/s (positive = ascending)
    double max_ascent_rate = 0.0;
    double avg_descent_rate = 0.0;  // m/s (positive = descending)
    double max_descent_rate = 0.0;

    size_t sample_count = 0;
};

struct WaypointData {
    double depth;           // meters
    double divetime;        // seconds from start
    std::optional<double> temperature;  // Kelvin (as in UDDF)
};

// Calculate dive statistics from a vector of waypoints
auto calculate_dive_stats(const std::vector<WaypointData>& waypoints) -> DiveStatistics;

} // namespace uddf2fit

#endif // UDDF2FIT_DIVE_STATS_HPP
