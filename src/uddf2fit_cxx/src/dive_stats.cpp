#include "uddf2fit/dive_stats.hpp"

#include <algorithm>
#include <cmath>
#include <limits>

namespace uddf2fit {

auto calculate_dive_stats(const std::vector<WaypointData>& waypoints) -> DiveStatistics {
    DiveStatistics stats;

    if (waypoints.empty()) {
        return stats;
    }

    stats.sample_count = waypoints.size();

    // Find max depth and accumulate for average
    double depth_sum = 0.0;
    double temp_sum = 0.0;
    size_t temp_count = 0;
    double min_temp = std::numeric_limits<double>::max();
    double max_temp = std::numeric_limits<double>::lowest();

    for (size_t i = 0; i < waypoints.size(); ++i) {
        const auto& wp = waypoints[i];
        depth_sum += wp.depth;

        if (wp.depth > stats.max_depth) {
            stats.max_depth = wp.depth;
            stats.max_depth_sample_index = i;
        }

        if (wp.temperature) {
            double temp_celsius = *wp.temperature - 273.15;
            temp_sum += temp_celsius;
            temp_count++;
            min_temp = std::min(min_temp, temp_celsius);
            max_temp = std::max(max_temp, temp_celsius);
        }
    }

    stats.avg_depth = depth_sum / static_cast<double>(waypoints.size());
    stats.bottom_time = waypoints.back().divetime;
    stats.descent_time = waypoints[stats.max_depth_sample_index].divetime;
    stats.ascent_time = stats.bottom_time - stats.descent_time;

    if (temp_count > 0) {
        stats.avg_temperature = temp_sum / static_cast<double>(temp_count);
        stats.min_temperature = min_temp;
        stats.max_temperature = max_temp;
    }

    // Calculate ascent/descent rates
    double ascent_distance = 0.0;
    double ascent_time = 0.0;
    double descent_distance = 0.0;
    double descent_time = 0.0;

    for (size_t i = 1; i < waypoints.size(); ++i) {
        double depth_change = waypoints[i - 1].depth - waypoints[i].depth;  // positive = ascending
        double time_delta = waypoints[i].divetime - waypoints[i - 1].divetime;

        if (time_delta <= 0) continue;

        double rate = std::abs(depth_change) / time_delta;

        if (depth_change > 0) {
            // Ascending
            ascent_distance += depth_change;
            ascent_time += time_delta;
            stats.max_ascent_rate = std::max(stats.max_ascent_rate, rate);
        } else if (depth_change < 0) {
            // Descending
            descent_distance -= depth_change;  // Make positive
            descent_time += time_delta;
            stats.max_descent_rate = std::max(stats.max_descent_rate, rate);
        }
    }

    if (ascent_time > 0) {
        stats.avg_ascent_rate = ascent_distance / ascent_time;
    }
    if (descent_time > 0) {
        stats.avg_descent_rate = descent_distance / descent_time;
    }

    return stats;
}

} // namespace uddf2fit
