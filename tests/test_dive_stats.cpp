#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "uddf2fit/dive_stats.hpp"

using Catch::Matchers::WithinRel;
using Catch::Matchers::WithinAbs;

TEST_CASE("calculate_dive_stats handles empty input", "[dive_stats]") {
    std::vector<uddf2fit::WaypointData> waypoints;
    auto stats = uddf2fit::calculate_dive_stats(waypoints);

    CHECK(stats.sample_count == 0);
    CHECK(stats.avg_depth == 0.0);
    CHECK(stats.max_depth == 0.0);
    CHECK(stats.bottom_time == 0.0);
}

TEST_CASE("calculate_dive_stats with single waypoint", "[dive_stats]") {
    std::vector<uddf2fit::WaypointData> waypoints = {
        {.depth = 10.0, .divetime = 60.0, .temperature = 300.15}
    };

    auto stats = uddf2fit::calculate_dive_stats(waypoints);

    CHECK(stats.sample_count == 1);
    CHECK(stats.avg_depth == 10.0);
    CHECK(stats.max_depth == 10.0);
    CHECK(stats.max_depth_sample_index == 0);
    CHECK(stats.bottom_time == 60.0);
    REQUIRE(stats.avg_temperature.has_value());
    CHECK_THAT(*stats.avg_temperature, WithinAbs(27.0, 0.1));
}

TEST_CASE("calculate_dive_stats with typical dive profile", "[dive_stats]") {
    // Simulate a simple dive: descent, bottom time, ascent
    std::vector<uddf2fit::WaypointData> waypoints = {
        {.depth = 0.0,  .divetime = 0.0,   .temperature = 300.15},   // Surface
        {.depth = 5.0,  .divetime = 30.0,  .temperature = 299.15},   // Descending
        {.depth = 10.0, .divetime = 60.0,  .temperature = 298.15},   // Descending
        {.depth = 15.0, .divetime = 90.0,  .temperature = 297.15},   // Descending
        {.depth = 20.0, .divetime = 120.0, .temperature = 296.15},   // Max depth
        {.depth = 20.0, .divetime = 600.0, .temperature = 296.15},   // Bottom time
        {.depth = 15.0, .divetime = 660.0, .temperature = 297.15},   // Ascending
        {.depth = 10.0, .divetime = 720.0, .temperature = 298.15},   // Ascending
        {.depth = 5.0,  .divetime = 780.0, .temperature = 299.15},   // Safety stop
        {.depth = 5.0,  .divetime = 960.0, .temperature = 299.15},   // Safety stop
        {.depth = 0.0,  .divetime = 1020.0, .temperature = 300.15},  // Surface
    };

    auto stats = uddf2fit::calculate_dive_stats(waypoints);

    SECTION("basic statistics") {
        CHECK(stats.sample_count == 11);
        CHECK(stats.max_depth == 20.0);
        CHECK(stats.bottom_time == 1020.0);
    }

    SECTION("max depth tracking") {
        CHECK(stats.max_depth_sample_index == 4);  // First sample at 20m
        CHECK(stats.descent_time == 120.0);  // Time to reach max depth
    }

    SECTION("average depth") {
        // Sum: 0+5+10+15+20+20+15+10+5+5+0 = 105, avg = 105/11 ≈ 9.545
        CHECK_THAT(stats.avg_depth, WithinAbs(9.545, 0.01));
    }

    SECTION("temperature statistics") {
        REQUIRE(stats.avg_temperature.has_value());
        REQUIRE(stats.min_temperature.has_value());
        REQUIRE(stats.max_temperature.has_value());

        // Temps in Celsius: 27, 26, 25, 24, 23, 23, 24, 25, 26, 26, 27
        CHECK_THAT(*stats.min_temperature, WithinAbs(23.0, 0.1));
        CHECK_THAT(*stats.max_temperature, WithinAbs(27.0, 0.1));
    }

    SECTION("ascent time") {
        // Ascent starts at sample 5 (divetime 600) and ends at sample 10 (divetime 1020)
        // ascent_time = bottom_time - descent_time = 1020 - 120 = 900
        CHECK_THAT(stats.ascent_time, WithinAbs(900.0, 0.1));
    }
}

TEST_CASE("calculate_dive_stats ascent/descent rates", "[dive_stats]") {
    // Simple dive: 30 seconds descent to 15m, 30 seconds at depth, 60 seconds ascent
    std::vector<uddf2fit::WaypointData> waypoints = {
        {.depth = 0.0,  .divetime = 0.0,  .temperature = std::nullopt},
        {.depth = 15.0, .divetime = 30.0, .temperature = std::nullopt},  // 0.5 m/s descent
        {.depth = 15.0, .divetime = 60.0, .temperature = std::nullopt},  // At depth
        {.depth = 0.0,  .divetime = 120.0, .temperature = std::nullopt}, // 0.25 m/s ascent
    };

    auto stats = uddf2fit::calculate_dive_stats(waypoints);

    SECTION("descent rate") {
        // Descent: 15m in 30s = 0.5 m/s
        CHECK_THAT(stats.avg_descent_rate, WithinAbs(0.5, 0.01));
        CHECK_THAT(stats.max_descent_rate, WithinAbs(0.5, 0.01));
    }

    SECTION("ascent rate") {
        // Ascent: 15m in 60s = 0.25 m/s
        CHECK_THAT(stats.avg_ascent_rate, WithinAbs(0.25, 0.01));
        CHECK_THAT(stats.max_ascent_rate, WithinAbs(0.25, 0.01));
    }
}

TEST_CASE("calculate_dive_stats without temperature", "[dive_stats]") {
    std::vector<uddf2fit::WaypointData> waypoints = {
        {.depth = 0.0,  .divetime = 0.0,  .temperature = std::nullopt},
        {.depth = 10.0, .divetime = 60.0, .temperature = std::nullopt},
        {.depth = 0.0,  .divetime = 120.0, .temperature = std::nullopt},
    };

    auto stats = uddf2fit::calculate_dive_stats(waypoints);

    CHECK_FALSE(stats.avg_temperature.has_value());
    CHECK_FALSE(stats.min_temperature.has_value());
    CHECK_FALSE(stats.max_temperature.has_value());
}

TEST_CASE("calculate_dive_stats with partial temperature data", "[dive_stats]") {
    std::vector<uddf2fit::WaypointData> waypoints = {
        {.depth = 0.0,  .divetime = 0.0,  .temperature = std::nullopt},
        {.depth = 10.0, .divetime = 60.0, .temperature = 298.15},  // 25°C
        {.depth = 10.0, .divetime = 120.0, .temperature = 296.15}, // 23°C
        {.depth = 0.0,  .divetime = 180.0, .temperature = std::nullopt},
    };

    auto stats = uddf2fit::calculate_dive_stats(waypoints);

    REQUIRE(stats.avg_temperature.has_value());
    CHECK_THAT(*stats.avg_temperature, WithinAbs(24.0, 0.1));  // (25+23)/2
    CHECK_THAT(*stats.min_temperature, WithinAbs(23.0, 0.1));
    CHECK_THAT(*stats.max_temperature, WithinAbs(25.0, 0.1));
}

TEST_CASE("calculate_dive_stats handles yo-yo dive profile", "[dive_stats]") {
    // Dive with multiple ascents/descents
    std::vector<uddf2fit::WaypointData> waypoints = {
        {.depth = 0.0,  .divetime = 0.0,   .temperature = std::nullopt},
        {.depth = 20.0, .divetime = 60.0,  .temperature = std::nullopt},  // First descent
        {.depth = 10.0, .divetime = 120.0, .temperature = std::nullopt},  // Partial ascent
        {.depth = 25.0, .divetime = 180.0, .temperature = std::nullopt},  // Second descent (max)
        {.depth = 15.0, .divetime = 240.0, .temperature = std::nullopt},  // Partial ascent
        {.depth = 0.0,  .divetime = 300.0, .temperature = std::nullopt},  // Final ascent
    };

    auto stats = uddf2fit::calculate_dive_stats(waypoints);

    CHECK(stats.max_depth == 25.0);
    CHECK(stats.max_depth_sample_index == 3);
    CHECK(stats.descent_time == 180.0);  // Time to reach max depth
    CHECK(stats.bottom_time == 300.0);
}
