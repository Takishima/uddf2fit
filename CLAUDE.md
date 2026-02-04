# CLAUDE.md - AI Assistant Guide for uddf2fit

## Project Overview

**uddf2fit** is a C++20 application that converts dive log data from UDDF (Universal Dive Data Format) XML files to Garmin FIT (Flexible and Interoperable Data Transfer) binary format. This enables importing dive logs into Garmin Connect and Garmin dive computers.

**Key characteristics:**
- One FIT file is generated per dive
- Written in modern C++20 with CMake build system
- Two parser backends available: xsdcxx (Xerces-C) or PugiXML
- Licensed under GNU GPL v2

## Codebase Structure

```
uddf2fit/
├── CMakeLists.txt              # Main CMake configuration
├── CMakePresets.json           # Build presets (debug/release/relwithdebinfo)
├── IMPLEMENTATION_PLAN.md      # Technical reference for data mappings
├── pyproject.toml              # Python tooling configuration
├── .clang-format               # C++ code style (LLVM-based, 99 col)
├── .pre-commit-config.yaml     # Pre-commit hooks
│
├── src/
│   ├── garmin_fit_sdk_cxx/     # Garmin FIT SDK library
│   │   ├── include/garmin_fit_sdk/  # FIT message types & encoding
│   │   └── src/                # SDK implementation
│   │
│   ├── uddf_parser_cxx/        # xsdcxx-generated UDDF parser (Xerces-C)
│   │   └── src/generated/      # Auto-generated from XSD schema
│   │
│   ├── uddf_parser_pugi/       # PugiXML-based UDDF parser (lightweight)
│   │   ├── include/uddf2fit/   # uddf_parser.hpp, uddf_types.hpp
│   │   └── src/                # Parser implementation
│   │
│   └── uddf2fit_cxx/           # Main converter application
│       ├── include/uddf2fit/   # Public headers
│       │   ├── conversions.hpp # Unit conversion functions
│       │   ├── dive_stats.hpp  # Dive statistics calculation
│       │   └── fit_writer.hpp  # FIT file writing
│       └── src/
│           ├── uddf2fit.cpp      # Main entry (xsdcxx backend)
│           ├── uddf2fit_pugi.cpp # Main entry (PugiXML backend)
│           ├── conversions.cpp
│           ├── dive_stats.cpp
│           └── fit_writer.cpp
│
├── tests/
│   ├── CMakeLists.txt
│   ├── test_conversions.cpp    # Unit tests for conversions
│   └── test_dive_stats.cpp     # Unit tests for statistics
│
├── tools/
│   └── decode_fit.py           # Python FIT file decoder utility
│
└── data/                       # Sample files for testing
    ├── mk3i.uddf               # Sample UDDF from Subsurface
    ├── mk3i_dl6.uddf           # UDDF from DiveLog 6
    ├── mk3i.fit                # Expected output
    └── 169 Plongee monogaz anonymized.fit  # Real Garmin reference
```

## Building the Project

### Prerequisites
- CMake 3.27+
- C++20 compatible compiler (GCC 11+, Clang 14+)
- For xsdcxx backend: Xerces-C (fetched automatically if not found)

### Build Commands

```bash
# Configure with debug preset (recommended for development)
cmake --preset debug

# Build
cmake --build build/debug

# Run tests
ctest --test-dir build/debug

# Release build
cmake --preset release
cmake --build build/release
```

### Parser Backend Selection

```bash
# Use PugiXML backend (lightweight, faster builds)
cmake --preset debug -DUDDF2FIT_PARSER=uxsdcxx

# Use xsdcxx backend (full schema validation)
cmake --preset debug -DUDDF2FIT_PARSER=xsdcxx
```

## Running the Converter

```bash
# Basic usage
./build/debug/src/uddf2fit_cxx/uddf2fit <uddf_file> <output_dir>

# With custom dive numbering
./build/debug/src/uddf2fit_cxx/uddf2fit input.uddf output/ --start-number 42

# Help
./build/debug/src/uddf2fit_cxx/uddf2fit --help
```

**CLI Options (PugiXML backend only):**
- `-n, --start-number N`: Start dive numbering at N (default: 1)
- `-h, --help`: Show help message

## Code Conventions

### C++ Style
- **Standard:** C++20
- **Formatting:** LLVM-based via `.clang-format` (99 column limit, 4-space indent)
- **Function returns:** Use trailing return type syntax (`auto foo() -> int`)
- **Namespaces:** `uddf2fit::` for public API, anonymous namespace for file-local helpers
- **Optionals:** Use `std::optional<T>` for nullable values

### Key Constants
- **FIT_EPOCH_OFFSET:** 631065600 (seconds from Unix epoch to FIT epoch: Dec 31, 1989 00:00:00 UTC)

### Unit Conversions (in `conversions.hpp`)
```cpp
kelvin_to_celsius(T kelvin) -> int8_t      // Temperature
fraction_to_percent(double f) -> uint8_t    // Gas mix (0.0-1.0 → 0-100)
degrees_to_semicircles(double deg) -> int32_t  // GPS coordinates
iso_to_fit_timestamp(string) -> FIT_DATE_TIME  // ISO 8601 → FIT timestamp
```

### Pre-commit Hooks
Run before committing:
```bash
pre-commit run --all-files
```

Hooks include: ruff (Python), clang-format (C++), typos, shellcheck, yamllint

## Testing

### Test Framework
- **Catch2 3.5.2** with CTest integration

### Running Tests
```bash
# Run all tests
ctest --test-dir build/debug

# Run with verbose output
ctest --test-dir build/debug -V

# Run specific test
./build/debug/tests/uddf2fit_tests "[conversions]"
```

### Test Structure
- Tests use `TEST_CASE` and `SECTION` macros
- Located in `tests/test_*.cpp`
- Link against `uddf2fit_lib` static library

## Key Implementation Details

### Data Flow
1. Parse UDDF XML file (via selected parser backend)
2. Extract dive data: waypoints, gas mixes, location, settings
3. Calculate dive statistics (depth, temperature, rates)
4. Write FIT messages in correct order
5. Output one `.fit` file per dive

### FIT Message Order (Critical)
```
file_id → device_info → sport → dive_settings → dive_gas →
event(timer_start) → record* → event(timer_stop) →
lap → session → dive_summary(session) → dive_summary(lap) → activity
```

### Extended Dive Data (PugiXML backend)
- Heart rate, CNS load, pO2 (measured/calculated)
- NDL time, deco stop info
- OTU tracking
- Gradient factors (GF low/high)
- Water density

### Decompression Model Support
- FIT only supports Bühlmann ZHL-16C
- Warnings emitted for RGBM/VPM models

## Common Tasks

### Adding a New FIT Field
1. Check field availability in `garmin_fit_sdk/fit_*_mesg.hpp`
2. Add to appropriate `write_*` method in `fit_writer.cpp`
3. Update corresponding parser to extract the data
4. Add unit tests

### Adding a New CLI Option
1. Modify `print_usage()` and argument parsing in `uddf2fit_pugi.cpp`
2. The xsdcxx backend (`uddf2fit.cpp`) uses simpler argv parsing

### Debugging FIT Output
```bash
# Decode a FIT file to readable format
python tools/decode_fit.py output.fit
```

## Reference Files

- **IMPLEMENTATION_PLAN.md**: Detailed UDDF→FIT field mappings and technical decisions
- **data/decoded_fit_output.txt**: Reference decoded output from real Garmin device
- **data/*.uddf**: Sample input files for testing

## Dependencies (Fetched via CMake FetchContent)

| Library | Version | Purpose |
|---------|---------|---------|
| Catch2 | 3.5.2 | Testing framework |
| PugiXML | 1.14 | XML parsing (uxsdcxx backend) |
| Xerces-C | 3.2.5 | XML parsing (xsdcxx backend) |
| libxsd | master | xsdcxx runtime headers |

## Troubleshooting

### Build Errors
- **Missing Xerces-C**: Use `-DUDDF2FIT_PARSER=uxsdcxx` for PugiXML backend
- **C++20 features**: Ensure compiler supports C++20 (GCC 11+, Clang 14+)

### Runtime Issues
- **"No dives found"**: Check UDDF file has `<profiledata>` with dives
- **"Dive has no samples"**: UDDF dive must have `<samples>` with waypoints
- **Non-Bühlmann warning**: FIT format only supports ZHL-16C decompression model
