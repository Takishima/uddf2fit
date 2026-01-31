#pragma once

#include "uddf_types.hpp"
#include <filesystem>
#include <memory>
#include <optional>
#include <string>

namespace uddf2fit {

// UDDF parser using pugixml
class UddfParser {
public:
    UddfParser() = default;
    ~UddfParser() = default;

    // Parse a UDDF file and return the document structure
    [[nodiscard]] auto parse(const std::filesystem::path& filename)
        -> std::optional<UddfDocument>;

    // Parse UDDF content from a string
    [[nodiscard]] auto parse_string(const std::string& content)
        -> std::optional<UddfDocument>;

    // Get the last error message
    [[nodiscard]] auto last_error() const -> const std::string& {
        return error_message_;
    }

private:
    std::string error_message_;
};

// Convenience function to load a UDDF file
[[nodiscard]] inline auto load_uddf(const std::filesystem::path& filename)
    -> std::optional<UddfDocument> {
    UddfParser parser;
    return parser.parse(filename);
}

} // namespace uddf2fit
