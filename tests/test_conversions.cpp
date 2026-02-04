#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <limits>

#include "uddf2fit/conversions.hpp"

using Catch::Matchers::WithinRel;
using Catch::Matchers::WithinAbs;

TEST_CASE("kelvin_to_celsius converts correctly", "[conversions]") {
    SECTION("freezing point of water") {
        CHECK(uddf2fit::kelvin_to_celsius(273.15) == 0);
    }

    SECTION("boiling point of water") {
        CHECK(uddf2fit::kelvin_to_celsius(373.15) == 100);
    }

    SECTION("typical dive water temperature") {
        // 300.15 K = 27°C (from real FIT file)
        CHECK(uddf2fit::kelvin_to_celsius(300.15) == 27);
    }

    SECTION("body temperature") {
        // 310.15 K = 37°C
        CHECK(uddf2fit::kelvin_to_celsius(310.15) == 37);
    }

    SECTION("cold water") {
        // 283.15 K = 10°C
        CHECK(uddf2fit::kelvin_to_celsius(283.15) == 10);
    }
}

TEST_CASE("fraction_to_percent converts correctly", "[conversions]") {
    SECTION("air oxygen content") {
        CHECK(uddf2fit::fraction_to_percent(0.21) == 21);
    }

    SECTION("pure oxygen") {
        CHECK(uddf2fit::fraction_to_percent(1.0) == 100);
    }

    SECTION("nitrox 32") {
        CHECK(uddf2fit::fraction_to_percent(0.32) == 32);
    }

    SECTION("zero helium") {
        CHECK(uddf2fit::fraction_to_percent(0.0) == 0);
    }

    SECTION("trimix helium content") {
        CHECK(uddf2fit::fraction_to_percent(0.35) == 35);
    }

    SECTION("rounds correctly") {
        // 0.215 should round to 22 (0.215 * 100 + 0.5 = 22.0)
        CHECK(uddf2fit::fraction_to_percent(0.215) == 22);
    }
}

TEST_CASE("degrees_to_semicircles converts correctly", "[conversions]") {
    SECTION("zero degrees") {
        CHECK(uddf2fit::degrees_to_semicircles(0.0) == 0);
    }

    SECTION("positive latitude") {
        // 28.049454° (from mk3i.uddf)
        auto result = uddf2fit::degrees_to_semicircles(28.049454);
        // Expected: 28.049454 * (2^31 / 180) ≈ 334712138
        CHECK(result > 334000000);
        CHECK(result < 335000000);
    }

    SECTION("negative latitude") {
        // From real FIT file: -8.xxx degrees → -158943587 semicircles
        // Let's verify the conversion formula
        auto result = uddf2fit::degrees_to_semicircles(-8.0);
        CHECK(result < 0);
        CHECK(result > -200000000);
    }

    SECTION("180 degrees wraps to min int (semicircle overflow)") {
        auto result = uddf2fit::degrees_to_semicircles(180.0);
        // 180 * (2^31 / 180) = 2^31, which overflows to -2^31 in int32
        // This is mathematically correct: 180° = -180° in circular representation
        CHECK(result == std::numeric_limits<int32_t>::min());
    }

    SECTION("-180 degrees equals min int") {
        auto result = uddf2fit::degrees_to_semicircles(-180.0);
        // -180 * (2^31 / 180) = -2^31
        CHECK(result == std::numeric_limits<int32_t>::min());
    }
}

TEST_CASE("parse_iso_datetime parses correctly", "[conversions]") {
    SECTION("standard format") {
        auto timestamp = uddf2fit::parse_iso_datetime("2024-05-29T09:22:06");
        // Should be Unix timestamp for 2024-05-29 09:22:06 UTC
        // Verified with Python: datetime(2024,5,29,9,22,6,tzinfo=UTC).timestamp() = 1716974526
        CHECK(timestamp == 1716974526);
    }

    SECTION("beginning of 2024") {
        auto timestamp = uddf2fit::parse_iso_datetime("2024-01-01T00:00:00");
        // 2024-01-01 00:00:00 UTC = 1704067200
        CHECK(timestamp == 1704067200);
    }

    SECTION("end of year") {
        auto timestamp = uddf2fit::parse_iso_datetime("2024-12-31T23:59:59");
        // 2024-12-31 23:59:59 UTC = 1735689599
        CHECK(timestamp == 1735689599);
    }
}

TEST_CASE("unix_to_fit_timestamp converts correctly", "[conversions]") {
    SECTION("FIT epoch offset is correct") {
        // Unix timestamp 0 (1970-01-01) should give negative FIT timestamp
        // because FIT epoch is 1989-12-31
        auto fit_ts = uddf2fit::unix_to_fit_timestamp(0);
        CHECK(fit_ts == static_cast<FIT_DATE_TIME>(-631065600));
    }

    SECTION("FIT epoch itself") {
        // 1989-12-31 00:00:00 UTC = Unix timestamp 631065600
        auto fit_ts = uddf2fit::unix_to_fit_timestamp(631065600);
        CHECK(fit_ts == 0);
    }

    SECTION("2024 timestamp") {
        // 2024-05-29 09:22:06 UTC
        auto unix_ts = uddf2fit::parse_iso_datetime("2024-05-29T09:22:06");
        auto fit_ts = uddf2fit::unix_to_fit_timestamp(unix_ts);
        // Should be unix_ts - 631065600
        CHECK(fit_ts == unix_ts - 631065600);
    }
}

TEST_CASE("iso_to_fit_timestamp combines parsing and conversion", "[conversions]") {
    SECTION("direct conversion") {
        auto fit_ts = uddf2fit::iso_to_fit_timestamp("2024-05-29T09:22:06");
        auto expected = uddf2fit::parse_iso_datetime("2024-05-29T09:22:06") - uddf2fit::FIT_EPOCH_OFFSET;
        CHECK(fit_ts == expected);
    }
}
