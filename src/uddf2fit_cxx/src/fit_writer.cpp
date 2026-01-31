#include "uddf2fit/fit_writer.hpp"

#include <garmin_fit_sdk/fit_activity_mesg.hpp>
#include <garmin_fit_sdk/fit_device_info_mesg.hpp>
#include <garmin_fit_sdk/fit_dive_gas_mesg.hpp>
#include <garmin_fit_sdk/fit_dive_settings_mesg.hpp>
#include <garmin_fit_sdk/fit_dive_summary_mesg.hpp>
#include <garmin_fit_sdk/fit_event_mesg.hpp>
#include <garmin_fit_sdk/fit_file_id_mesg.hpp>
#include <garmin_fit_sdk/fit_lap_mesg.hpp>
#include <garmin_fit_sdk/fit_profile.hpp>
#include <garmin_fit_sdk/fit_record_mesg.hpp>
#include <garmin_fit_sdk/fit_session_mesg.hpp>
#include <garmin_fit_sdk/fit_sport_mesg.hpp>

#include "uddf2fit/conversions.hpp"

namespace uddf2fit {

DiveFitWriter::DiveFitWriter(const std::filesystem::path& output_path)
    : encoder_(fit::ProtocolVersion::V20) {
    file_.open(output_path, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    if (file_.is_open()) {
        encoder_.Open(file_);
        is_open_ = true;
    }
}

DiveFitWriter::~DiveFitWriter() {
    if (is_open_) {
        close();
    }
}

bool DiveFitWriter::close() {
    if (!is_open_) return false;
    bool result = encoder_.Close() == FIT_TRUE;
    file_.close();
    is_open_ = false;
    return result;
}

void DiveFitWriter::write_file_id(FIT_DATE_TIME time_created) {
    fit::FileIdMesg msg;
    msg.SetType(FIT_FILE_ACTIVITY);
    msg.SetManufacturer(FIT_MANUFACTURER_DEVELOPMENT);
    msg.SetProduct(1);
    msg.SetSerialNumber(12345678);
    msg.SetTimeCreated(time_created);
    encoder_.Write(msg);
}

void DiveFitWriter::write_device_info(FIT_DATE_TIME timestamp) {
    fit::DeviceInfoMesg msg;
    msg.SetTimestamp(timestamp);
    msg.SetDeviceIndex(FIT_DEVICE_INDEX_CREATOR);
    msg.SetManufacturer(FIT_MANUFACTURER_DEVELOPMENT);
    msg.SetProduct(1);
    msg.SetSoftwareVersion(100);  // 1.00
    encoder_.Write(msg);
}

void DiveFitWriter::write_sport() {
    fit::SportMesg msg;
    msg.SetSport(FIT_SPORT_DIVING);
    msg.SetSubSport(FIT_SUB_SPORT_SINGLE_GAS_DIVING);
    encoder_.Write(msg);
}

void DiveFitWriter::write_dive_settings() {
    fit::DiveSettingsMesg msg;
    msg.SetMessageIndex(0);
    msg.SetModel(FIT_TISSUE_MODEL_TYPE_ZHL_16C);
    msg.SetGfLow(40);
    msg.SetGfHigh(85);
    msg.SetWaterType(FIT_WATER_TYPE_SALT);
    msg.SetWaterDensity(1025.0f);
    msg.SetPo2Warn(1.4f);
    msg.SetPo2Critical(1.6f);
    msg.SetSafetyStopEnabled(FIT_TRUE);
    msg.SetSafetyStopTime(180);
    encoder_.Write(msg);
}

void DiveFitWriter::write_dive_gas(const std::vector<GasMix>& gases) {
    for (size_t i = 0; i < gases.size(); ++i) {
        fit::DiveGasMesg msg;
        msg.SetMessageIndex(static_cast<FIT_MESSAGE_INDEX>(i));
        msg.SetOxygenContent(gases[i].oxygen_percent);
        msg.SetHeliumContent(gases[i].helium_percent);
        msg.SetStatus(FIT_DIVE_GAS_STATUS_ENABLED);
        msg.SetMode(FIT_DIVE_GAS_MODE_OPEN_CIRCUIT);
        encoder_.Write(msg);
    }
}

void DiveFitWriter::write_event_timer_start(FIT_DATE_TIME timestamp) {
    fit::EventMesg msg;
    msg.SetTimestamp(timestamp);
    msg.SetEvent(FIT_EVENT_TIMER);
    msg.SetEventType(FIT_EVENT_TYPE_START);
    msg.SetEventGroup(0);
    encoder_.Write(msg);

    // Also write initial gas switch event
    fit::EventMesg gas_msg;
    gas_msg.SetTimestamp(timestamp);
    gas_msg.SetEvent(FIT_EVENT_DIVE_GAS_SWITCHED);
    gas_msg.SetEventType(FIT_EVENT_TYPE_MARKER);
    gas_msg.SetData(0);  // Gas index 0
    encoder_.Write(gas_msg);
}

void DiveFitWriter::write_event_gas_switch(FIT_DATE_TIME timestamp, uint8_t gas_index) {
    fit::EventMesg msg;
    msg.SetTimestamp(timestamp);
    msg.SetEvent(FIT_EVENT_DIVE_GAS_SWITCHED);
    msg.SetEventType(FIT_EVENT_TYPE_MARKER);
    msg.SetData(gas_index);
    encoder_.Write(msg);
}

void DiveFitWriter::write_event_timer_stop(FIT_DATE_TIME timestamp) {
    fit::EventMesg msg;
    msg.SetTimestamp(timestamp);
    msg.SetEvent(FIT_EVENT_TIMER);
    msg.SetEventType(FIT_EVENT_TYPE_STOP_ALL);
    msg.SetEventGroup(0);
    encoder_.Write(msg);
}

void DiveFitWriter::write_record(FIT_DATE_TIME timestamp,
                                  double depth,
                                  std::optional<int8_t> temperature,
                                  std::optional<double> ascent_rate) {
    fit::RecordMesg msg;
    msg.SetTimestamp(timestamp);
    msg.SetDepth(static_cast<FIT_FLOAT32>(depth));

    if (temperature) {
        msg.SetTemperature(*temperature);
    }

    if (ascent_rate) {
        msg.SetAscentRate(static_cast<FIT_FLOAT32>(*ascent_rate));
    }

    encoder_.Write(msg);
}

void DiveFitWriter::write_lap(FIT_DATE_TIME start_time,
                               FIT_DATE_TIME end_time,
                               const DiveStatistics& stats,
                               bool is_multi_gas) {
    fit::LapMesg msg;
    msg.SetMessageIndex(0);
    msg.SetTimestamp(end_time);
    msg.SetStartTime(start_time);
    msg.SetTotalElapsedTime(static_cast<FIT_FLOAT32>(stats.bottom_time));
    msg.SetTotalTimerTime(static_cast<FIT_FLOAT32>(stats.bottom_time));
    msg.SetEvent(FIT_EVENT_LAP);
    msg.SetEventType(FIT_EVENT_TYPE_STOP);
    msg.SetSport(FIT_SPORT_DIVING);
    msg.SetSubSport(is_multi_gas ? FIT_SUB_SPORT_MULTI_GAS_DIVING : FIT_SUB_SPORT_SINGLE_GAS_DIVING);
    msg.SetLapTrigger(FIT_LAP_TRIGGER_SESSION_END);
    msg.SetIntensity(FIT_INTENSITY_ACTIVE);

    if (stats.avg_temperature) {
        msg.SetAvgTemperature(static_cast<FIT_SINT8>(*stats.avg_temperature));
    }
    if (stats.max_temperature) {
        msg.SetMaxTemperature(static_cast<FIT_SINT8>(*stats.max_temperature));
    }
    if (stats.min_temperature) {
        msg.SetMinTemperature(static_cast<FIT_SINT8>(*stats.min_temperature));
    }

    encoder_.Write(msg);
}

void DiveFitWriter::write_session(FIT_DATE_TIME start_time,
                                   FIT_DATE_TIME end_time,
                                   const DiveStatistics& stats,
                                   const std::optional<GeoLocation>& location,
                                   bool is_multi_gas) {
    fit::SessionMesg msg;
    msg.SetMessageIndex(0);
    msg.SetTimestamp(end_time);
    msg.SetStartTime(start_time);
    msg.SetTotalElapsedTime(static_cast<FIT_FLOAT32>(stats.bottom_time));
    msg.SetTotalTimerTime(static_cast<FIT_FLOAT32>(stats.bottom_time));
    msg.SetEvent(FIT_EVENT_SESSION);
    msg.SetEventType(FIT_EVENT_TYPE_STOP);
    msg.SetSport(FIT_SPORT_DIVING);
    msg.SetSubSport(is_multi_gas ? FIT_SUB_SPORT_MULTI_GAS_DIVING : FIT_SUB_SPORT_SINGLE_GAS_DIVING);
    msg.SetFirstLapIndex(0);
    msg.SetNumLaps(1);
    msg.SetTrigger(FIT_SESSION_TRIGGER_ACTIVITY_END);

    if (location) {
        msg.SetStartPositionLat(degrees_to_semicircles(location->latitude));
        msg.SetStartPositionLong(degrees_to_semicircles(location->longitude));
        msg.SetEndPositionLat(degrees_to_semicircles(location->latitude));
        msg.SetEndPositionLong(degrees_to_semicircles(location->longitude));
    }

    if (stats.avg_temperature) {
        msg.SetAvgTemperature(static_cast<FIT_SINT8>(*stats.avg_temperature));
    }
    if (stats.max_temperature) {
        msg.SetMaxTemperature(static_cast<FIT_SINT8>(*stats.max_temperature));
    }
    if (stats.min_temperature) {
        msg.SetMinTemperature(static_cast<FIT_SINT8>(*stats.min_temperature));
    }

    encoder_.Write(msg);
}

void DiveFitWriter::write_dive_summary(FIT_DATE_TIME timestamp,
                                        const DiveStatistics& stats,
                                        uint32_t dive_number,
                                        uint32_t surface_interval,
                                        FIT_MESG_NUM reference_mesg,
                                        uint16_t reference_index) {
    fit::DiveSummaryMesg msg;
    msg.SetTimestamp(timestamp);
    msg.SetReferenceMesg(reference_mesg);
    msg.SetReferenceIndex(reference_index);
    msg.SetAvgDepth(static_cast<FIT_FLOAT32>(stats.avg_depth));
    msg.SetMaxDepth(static_cast<FIT_FLOAT32>(stats.max_depth));
    msg.SetBottomTime(static_cast<FIT_FLOAT32>(stats.bottom_time));
    msg.SetDiveNumber(dive_number);
    msg.SetSurfaceInterval(surface_interval);
    msg.SetDescentTime(static_cast<FIT_FLOAT32>(stats.descent_time));
    msg.SetAscentTime(static_cast<FIT_FLOAT32>(stats.ascent_time));
    msg.SetAvgAscentRate(static_cast<FIT_FLOAT32>(stats.avg_ascent_rate));
    msg.SetAvgDescentRate(static_cast<FIT_FLOAT32>(stats.avg_descent_rate));
    msg.SetMaxAscentRate(static_cast<FIT_FLOAT32>(stats.max_ascent_rate));
    msg.SetMaxDescentRate(static_cast<FIT_FLOAT32>(stats.max_descent_rate));

    // Default CNS/N2 values (not available in basic UDDF)
    msg.SetStartCns(0);
    msg.SetEndCns(0);
    msg.SetStartN2(0);
    msg.SetEndN2(0);

    encoder_.Write(msg);
}

void DiveFitWriter::write_activity(FIT_DATE_TIME timestamp, uint32_t total_elapsed_time) {
    fit::ActivityMesg msg;
    msg.SetTimestamp(timestamp);
    msg.SetTotalTimerTime(static_cast<FIT_FLOAT32>(total_elapsed_time));
    msg.SetNumSessions(1);
    msg.SetType(FIT_ACTIVITY_MANUAL);
    msg.SetEvent(FIT_EVENT_ACTIVITY);
    msg.SetEventType(FIT_EVENT_TYPE_STOP);
    encoder_.Write(msg);
}

} // namespace uddf2fit
