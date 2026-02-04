# UDDF to FIT Converter - Implementation Plan

## Executive Summary

This document outlines the implementation plan for completing the UDDF to FIT converter. The analysis is based on:
- Existing codebase (C++ UDDF parser, Garmin FIT SDK)
- Sample UDDF file (`data/mk3i.uddf`) from Subsurface
- **Real Garmin Descent Mk3i FIT file** (`data/169 Plongee monogaz anonymized.fit`)

## 1. Architecture Decision

**Language: C++**

Rationale:
- Python FIT SDK is decoder-only (no encoder)
- C++ FIT SDK provides `fit::Encode` for writing FIT files
- Existing UDDF parser is C++ (xsdcxx-generated)
- Partial converter already links both libraries

**Output: One FIT file per dive**

Rationale:
- Matches Garmin dive computer export behavior
- Garmin Connect expects one activity per file
- UDDF can contain multiple dives; each becomes a separate FIT file

---

## 2. Real FIT File Analysis (Garmin Descent Mk3i)

### 2.1 Message Structure (from decoded `169 Plongee monogaz anonymized.fit`)

| Message Type | Count | Purpose |
|-------------|-------|---------|
| `file_id` | 1 | File identification (type=activity, product=descent_mk3i) |
| `file_creator` | 1 | Software version |
| `device_info` | 7 | Device/sensor metadata |
| `dive_settings` | 1 | Deco model (ZHL-16C), GF, PO2 limits, water type |
| `dive_gas` | 1 | Gas mix (O2=21%, He=0%, mode=open_circuit) |
| `dive_alarm` | 1 | Depth/time alarms configuration |
| `event` | 16 | Gas switch, timer start/stop, dive alerts |
| `record` | 3676 | Per-second dive samples |
| `tank_update` | 744 | Tank pressure readings (every ~5 seconds) |
| `lap` | 1 | Lap summary |
| `session` | 1 | Session summary (sport=diving, sub_sport=single_gas_diving) |
| `dive_summary` | 2 | One referencing session, one referencing lap |
| `activity` | 1 | Activity wrapper |
| `tank_summary` | 1 | Tank consumption summary |
| `gps_metadata` | 3 | GPS location data |

### 2.2 Key Field Values (from real file)

**Dive Summary:**
```
max_depth: 20.534 m
avg_depth: 13.728 m
bottom_time: 3923.903 s (65.4 min)
dive_number: 169
surface_interval: 24524 s (6.8 hours)
start_cns: 0%, end_cns: 5%
start_n2: 21%, end_n2: 82%
o2_toxicity: 8 OTUs
avg_rmv: 37.84 L/min
avg_pressure_sac: 1.05 bar/min
avg_ascent_rate: 0.045 m/s
```

**Record Sample (per-second):**
```
timestamp: absolute (FIT epoch)
depth: 1.779 m (float)
temperature: 27 (integer °C)
absolute_pressure: 119413 Pa
ascent_rate: -0.446 m/s (negative = descending)
cns_load: 0 %
n2_load: 20 %
po2: 0.25 bar
next_stop_depth: 0.0 m
next_stop_time: 0 s
time_to_surface: 11 s
```

**Session:**
```
sport: diving
sub_sport: single_gas_diving
start_position_lat: -158943587 semicircles
start_position_long: 574588649 semicircles
total_elapsed_time: 3954.772 s
avg_temperature: 28°C
min_temperature: 27°C
max_temperature: 28°C
```

---

## 3. Data Mapping (UDDF → FIT)

### 3.1 Unit Conversions

| UDDF Field | UDDF Unit | FIT Field | FIT Unit | Formula |
|------------|-----------|-----------|----------|---------|
| `<o2>` | fraction (0.21) | `oxygen_content` | percent (21) | `× 100` |
| `<he>` | fraction (0.0) | `helium_content` | percent (0) | `× 100` |
| `<temperature>` | Kelvin (310.15) | `temperature` | °C (37) | `- 273.15` |
| `<depth>` | meters | `depth` | meters | direct |
| `<divetime>` | seconds from start | `timestamp` | FIT epoch | `start_time + divetime` |
| `<latitude>` | degrees | `position_lat` | semicircles | `× (2³¹ / 180)` |
| `<longitude>` | degrees | `position_long` | semicircles | `× (2³¹ / 180)` |

### 3.2 Timestamp Conversion

FIT Epoch: **December 31, 1989 00:00:00 UTC**

```cpp
// Unix timestamp to FIT timestamp
constexpr uint32_t FIT_EPOCH_OFFSET = 631065600;
FIT_DATE_TIME fit_ts = unix_timestamp - FIT_EPOCH_OFFSET;
```

### 3.3 Message Field Mappings

#### file_id_mesg
| FIT Field | Source | Value |
|-----------|--------|-------|
| `type` | Constant | `FIT_FILE_ACTIVITY` |
| `manufacturer` | Constant | `FIT_MANUFACTURER_DEVELOPMENT` (255) |
| `product` | Constant | 1 (custom) |
| `serial_number` | Generated | Random or hash of dive ID |
| `time_created` | UDDF `<datetime>` | Converted dive start time |

#### dive_gas_mesg
| FIT Field | UDDF Source | Conversion |
|-----------|-------------|------------|
| `message_index` | Sequential | 0, 1, 2... |
| `oxygen_content` | `<mix>/<o2>` | fraction × 100 |
| `helium_content` | `<mix>/<he>` | fraction × 100 |
| `status` | Constant | `FIT_DIVE_GAS_STATUS_ENABLED` |
| `mode` | Constant | `FIT_DIVE_GAS_MODE_OPEN_CIRCUIT` |

#### record_mesg (per waypoint)
| FIT Field | UDDF Source | Conversion |
|-----------|-------------|------------|
| `timestamp` | `<divetime>` + start | Absolute FIT timestamp |
| `depth` | `<depth>` | Direct (float, meters) |
| `temperature` | `<temperature>` | Kelvin - 273.15 (int8, °C) |
| `ascent_rate` | Calculated | (prev_depth - curr_depth) / Δt |
| `cns_load` | `<cns>` or 0 | Direct or default |
| `n2_load` | Not in UDDF | 0 or omit |

#### dive_summary_mesg
| FIT Field | Source | Calculation |
|-----------|--------|-------------|
| `timestamp` | End time | Last sample timestamp |
| `reference_mesg` | Constant | `FIT_MESG_NUM_SESSION` or `FIT_MESG_NUM_LAP` |
| `reference_index` | Constant | 0 |
| `avg_depth` | Samples | Σ(depth) / count |
| `max_depth` | Samples | max(depth) |
| `bottom_time` | Samples | Last divetime |
| `dive_number` | UDDF `<divenumber>` | Direct |
| `surface_interval` | Calculated | Time since previous dive end |
| `start_cns` / `end_cns` | UDDF or default | 0 if not available |

#### session_mesg
| FIT Field | Source | Value |
|-----------|--------|-------|
| `sport` | Constant | `FIT_SPORT_DIVING` (53) |
| `sub_sport` | Gas count | `FIT_SUB_SPORT_SINGLE_GAS_DIVING` (57) or `MULTI_GAS_DIVING` (58) |
| `start_time` | UDDF `<datetime>` | Converted |
| `timestamp` | End time | Dive end timestamp |
| `total_elapsed_time` | Samples | Last divetime |
| `start_position_lat/long` | UDDF `<site>` | Converted coordinates |
| `avg_temperature` | Samples | Average of temps |

---

## 4. Implementation Tasks

### Phase 1: Core Infrastructure

#### Task 1.1: Conversion Utilities
**New file:** `src/uddf2fit_cxx/include/uddf2fit/conversions.hpp`

```cpp
namespace uddf2fit {
    // Temperature: Kelvin → Celsius
    FIT_SINT8 kelvin_to_celsius(double kelvin);

    // Gas fraction → percent
    FIT_UINT8 fraction_to_percent(double fraction);

    // Degrees → semicircles
    FIT_SINT32 degrees_to_semicircles(double degrees);

    // ISO datetime string → FIT timestamp
    FIT_DATE_TIME to_fit_timestamp(const std::string& iso_datetime);

    // xml_schema::date_time → FIT timestamp
    FIT_DATE_TIME to_fit_timestamp(const xml_schema::date_time& dt);
}
```

#### Task 1.2: Dive Statistics Calculator
**New file:** `src/uddf2fit_cxx/include/uddf2fit/dive_stats.hpp`

```cpp
struct DiveStatistics {
    double avg_depth;
    double max_depth;
    size_t max_depth_sample_index;
    double avg_temperature;  // Celsius
    double min_temperature;
    double max_temperature;
    double bottom_time;      // seconds
    double descent_time;     // time to max depth
    double ascent_time;      // time from max depth to surface
    double avg_ascent_rate;  // m/s (positive = ascending)
    double max_ascent_rate;
    double avg_descent_rate; // m/s (positive = descending)
    double max_descent_rate;
    size_t sample_count;
};

DiveStatistics calculate_dive_stats(const streit::samplesType& samples);
```

### Phase 2: FIT Message Writers

#### Task 2.1: FIT Writer Class
**New file:** `src/uddf2fit_cxx/include/uddf2fit/fit_writer.hpp`

```cpp
class DiveFitWriter {
public:
    explicit DiveFitWriter(const std::filesystem::path& output_path);
    ~DiveFitWriter();

    // Required messages (in order)
    void write_file_id(FIT_DATE_TIME time_created);
    void write_file_creator();
    void write_device_info(FIT_DATE_TIME timestamp);
    void write_dive_settings();  // defaults
    void write_dive_gas(const std::vector<GasMix>& gases);
    void write_event_timer_start(FIT_DATE_TIME timestamp);
    void write_event_gas_switch(FIT_DATE_TIME timestamp, uint8_t gas_index);
    void write_records(const streit::samplesType& samples,
                       FIT_DATE_TIME start_time);
    void write_event_timer_stop(FIT_DATE_TIME timestamp);
    void write_lap(FIT_DATE_TIME start, FIT_DATE_TIME end,
                   const DiveStatistics& stats, FIT_SUB_SPORT sub_sport);
    void write_session(FIT_DATE_TIME start, FIT_DATE_TIME end,
                       const DiveStatistics& stats,
                       const std::optional<GeoLocation>& location,
                       FIT_SUB_SPORT sub_sport);
    void write_dive_summary(FIT_DATE_TIME timestamp,
                           const DiveStatistics& stats,
                           uint32_t dive_number,
                           uint32_t surface_interval,
                           FIT_MESG_NUM reference_mesg);
    void write_activity(FIT_DATE_TIME timestamp, uint32_t total_time);

    bool close();

private:
    std::fstream file_;
    fit::Encode encoder_;
    bool is_open_ = false;
};
```

### Phase 3: Main Converter

#### Task 3.1: Refactor `uddf2fit.cpp`

```cpp
struct GasMix {
    uint8_t oxygen_percent;
    uint8_t helium_percent;
    std::string id;  // UDDF mix ID for reference
};

struct GeoLocation {
    double latitude;
    double longitude;
};

void convert_dive_to_fit(
    const streit::diveType& dive,
    const std::optional<GeoLocation>& location,
    const std::vector<GasMix>& gases,
    uint32_t surface_interval,
    const std::filesystem::path& output_path);

int main(int argc, char* argv[]) {
    // ... existing argument parsing ...

    FIT_DATE_TIME prev_dive_end = 0;
    int dive_index = 0;

    for (const auto& rep_group : uddf->profiledata()->repetitiongroup()) {
        for (const auto& dive : rep_group.dive()) {
            // Extract dive data
            auto location = extract_location(dive, dive_sites);
            auto gases = extract_gases(dive, gas_definitions);
            auto start_time = extract_start_time(dive);

            uint32_t surface_interval = (prev_dive_end > 0)
                ? (start_time - prev_dive_end)
                : 0xFFFFFFFF;  // unknown

            // Generate output filename
            auto filename = fmt::format("dive_{:03d}.fit", dive_index++);
            auto output_path = output_dir / filename;

            // Convert
            convert_dive_to_fit(dive, location, gases,
                               surface_interval, output_path);

            // Track for surface interval calculation
            prev_dive_end = calculate_end_time(dive, start_time);
        }
    }
}
```

### Phase 4: Testing

#### Task 4.1: Unit Tests
**File:** `tests/test_conversions.cpp`

```cpp
TEST(Conversions, KelvinToCelsius) {
    EXPECT_EQ(kelvin_to_celsius(273.15), 0);
    EXPECT_EQ(kelvin_to_celsius(310.15), 37);
    EXPECT_EQ(kelvin_to_celsius(300.15), 27);  // from real file
}

TEST(Conversions, FractionToPercent) {
    EXPECT_EQ(fraction_to_percent(0.21), 21);
    EXPECT_EQ(fraction_to_percent(0.32), 32);
    EXPECT_EQ(fraction_to_percent(0.0), 0);
}

TEST(Conversions, DegreesToSemicircles) {
    // Verify against real file values
    // lat -8.something degrees → -158943587 semicircles
    auto result = degrees_to_semicircles(-8.xxx);
    EXPECT_NEAR(result, -158943587, 1000);
}
```

#### Task 4.2: Integration Test
**File:** `tests/test_integration.cpp`

```cpp
TEST(Integration, ConvertMk3iUddf) {
    std::filesystem::path uddf = "data/mk3i.uddf";
    std::filesystem::path out_dir = "test_output";

    auto result = convert_uddf_file(uddf, out_dir);

    EXPECT_TRUE(result.success);
    EXPECT_GE(result.dive_count, 1);

    // Decode output and verify basic structure
    auto fit_path = out_dir / "dive_000.fit";
    EXPECT_TRUE(std::filesystem::exists(fit_path));

    // Verify FIT file is valid and contains expected messages
    // ...
}
```

---

## 5. Message Order in Output FIT File

Based on the real Garmin file, write messages in this order:

1. `file_id_mesg`
2. `file_creator_mesg` (optional)
3. `device_info_mesg` (optional)
4. `dive_settings_mesg` (with sensible defaults)
5. `dive_gas_mesg` (one per gas)
6. `event_mesg` (timer start)
7. `event_mesg` (initial gas switch)
8. `record_mesg` (all samples, chronologically)
9. `event_mesg` (gas switches during dive, if any)
10. `event_mesg` (timer stop)
11. `lap_mesg`
12. `session_mesg`
13. `dive_summary_mesg` (reference=session)
14. `dive_summary_mesg` (reference=lap)
15. `activity_mesg`

---

## 6. Handling Missing/Optional UDDF Data

| UDDF Field | If Missing | Default Value |
|------------|------------|---------------|
| `<temperature>` | Skip in record | N/A |
| `<divenumber>` | Use sequential index | 0, 1, 2... |
| `<site>` coordinates | Skip position fields | N/A |
| `<cns>` | Use 0 | 0 |
| NDL/deco data | Skip fields | N/A |
| Surface interval | First dive | 0xFFFFFFFF (invalid) |

---

## 7. Files to Create/Modify

### New Files
- `src/uddf2fit_cxx/include/uddf2fit/conversions.hpp`
- `src/uddf2fit_cxx/src/conversions.cpp`
- `src/uddf2fit_cxx/include/uddf2fit/dive_stats.hpp`
- `src/uddf2fit_cxx/src/dive_stats.cpp`
- `src/uddf2fit_cxx/include/uddf2fit/fit_writer.hpp`
- `src/uddf2fit_cxx/src/fit_writer.cpp`
- `tests/test_conversions.cpp`
- `tests/test_integration.cpp`

### Modify
- `src/uddf2fit_cxx/src/uddf2fit.cpp` (main converter logic)
- `src/uddf2fit_cxx/CMakeLists.txt` (add new sources)

---

## 8. Validation Strategy

1. **FIT SDK Validator**: Use Garmin's FIT SDK validator tool
2. **Round-trip Test**: UDDF → FIT → decode → compare values
3. **Garmin Connect Import**: Test actual import
4. **Reference Comparison**: Compare output structure to `data/169 Plongee monogaz anonymized.fit`

---

## 9. Known Limitations

1. **No decompression calculation**: UDDF from basic dive computers may lack NDL/deco data
2. **No tank pressure**: UDDF may not include tank pressure (T2 transmitter data)
3. **Proprietary messages**: Cannot replicate Garmin-specific message types (140, 288, etc.)
4. **Limited gas switch events**: Only when `<switchmix>` present in UDDF
