#ifndef UDDF2FIT_CONVERSIONS_HPP
#define UDDF2FIT_CONVERSIONS_HPP

#include <cstdint>
#include <string>

#include <garmin_fit_sdk/fit.hpp>

namespace uddf2fit {

// FIT epoch: December 31, 1989 00:00:00 UTC
// Difference from Unix epoch (Jan 1, 1970) in seconds
inline constexpr uint32_t FIT_EPOCH_OFFSET = 631065600;

// Temperature: Kelvin to Celsius (FIT uses integer Celsius)
inline auto kelvin_to_celsius(double kelvin) -> int8_t {
    return static_cast<int8_t>(kelvin - 273.15);
}

// Gas fraction (0.0-1.0) to percent (0-100)
inline auto fraction_to_percent(double fraction) -> uint8_t {
    return static_cast<uint8_t>(fraction * 100.0 + 0.5);
}

// Degrees to FIT semicircles
// FIT uses semicircles where 2^31 semicircles = 180 degrees
inline auto degrees_to_semicircles(double degrees) -> int32_t {
    constexpr double SEMICIRCLES_PER_DEGREE = 2147483648.0 / 180.0;
    return static_cast<int32_t>(degrees * SEMICIRCLES_PER_DEGREE);
}

// Parse ISO 8601 datetime string to Unix timestamp
// Format: "2024-05-29T09:22:06"
auto parse_iso_datetime(const std::string& datetime) -> uint32_t;

// Convert Unix timestamp to FIT timestamp
inline auto unix_to_fit_timestamp(uint32_t unix_ts) -> FIT_DATE_TIME {
    return unix_ts - FIT_EPOCH_OFFSET;
}

// Parse ISO datetime directly to FIT timestamp
inline auto iso_to_fit_timestamp(const std::string& datetime) -> FIT_DATE_TIME {
    return unix_to_fit_timestamp(parse_iso_datetime(datetime));
}

} // namespace uddf2fit

#endif // UDDF2FIT_CONVERSIONS_HPP
