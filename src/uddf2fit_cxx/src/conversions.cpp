#include "uddf2fit/conversions.hpp"

#include <ctime>
#include <stdexcept>

namespace uddf2fit {

auto parse_iso_datetime(const std::string& datetime) -> uint32_t {
    std::tm tm = {};

    // Parse "YYYY-MM-DDTHH:MM:SS" format
    if (datetime.length() < 19) {
        throw std::invalid_argument("Invalid datetime format: " + datetime);
    }

    tm.tm_year = std::stoi(datetime.substr(0, 4)) - 1900;
    tm.tm_mon = std::stoi(datetime.substr(5, 2)) - 1;
    tm.tm_mday = std::stoi(datetime.substr(8, 2));
    tm.tm_hour = std::stoi(datetime.substr(11, 2));
    tm.tm_min = std::stoi(datetime.substr(14, 2));
    tm.tm_sec = std::stoi(datetime.substr(17, 2));
    tm.tm_isdst = 0;

    // Use timegm for UTC (or portable alternative)
#ifdef _WIN32
    return static_cast<uint32_t>(_mkgmtime(&tm));
#else
    return static_cast<uint32_t>(timegm(&tm));
#endif
}

} // namespace uddf2fit
