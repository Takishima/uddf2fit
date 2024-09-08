/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2024 Garmin International, Inc.
// Licensed under the Flexible and Interoperable Data Transfer (FIT) Protocol License; you
// may not use this file except in compliance with the Flexible and Interoperable Data
// Transfer (FIT) Protocol License.
/////////////////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 21.141.0Release
// Tag = production/release/21.141.0-0-g2aa27e1
/////////////////////////////////////////////////////////////////////////////////////////////

#if !defined(FIT_ONE_D_SENSOR_CALIBRATION_MESG_HPP)
#    define FIT_ONE_D_SENSOR_CALIBRATION_MESG_HPP

#    include "fit_mesg.hpp"

namespace fit {

class OneDSensorCalibrationMesg : public Mesg {
public:
    class FieldDefNum final {
    public:
        static const FIT_UINT8 Timestamp = 253;
        static const FIT_UINT8 SensorType = 0;
        static const FIT_UINT8 CalibrationFactor = 1;
        static const FIT_UINT8 CalibrationDivisor = 2;
        static const FIT_UINT8 LevelShift = 3;
        static const FIT_UINT8 OffsetCal = 4;
        static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    OneDSensorCalibrationMesg(void) : Mesg(Profile::MESG_ONE_D_SENSOR_CALIBRATION) {}

    OneDSensorCalibrationMesg(const Mesg &mesg) : Mesg(mesg) {}

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of timestamp field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsTimestampValid() const {
        const Field *field = GetField(253);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns timestamp field
    // Units: s
    // Comment: Whole second part of the timestamp
    ///////////////////////////////////////////////////////////////////////
    FIT_DATE_TIME GetTimestamp(void) const {
        return GetFieldUINT32Value(253, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set timestamp field
    // Units: s
    // Comment: Whole second part of the timestamp
    ///////////////////////////////////////////////////////////////////////
    void SetTimestamp(FIT_DATE_TIME timestamp) {
        SetFieldUINT32Value(253, timestamp, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of sensor_type field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsSensorTypeValid() const {
        const Field *field = GetField(0);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns sensor_type field
    // Comment: Indicates which sensor the calibration is for
    ///////////////////////////////////////////////////////////////////////
    FIT_SENSOR_TYPE GetSensorType(void) const {
        return GetFieldENUMValue(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set sensor_type field
    // Comment: Indicates which sensor the calibration is for
    ///////////////////////////////////////////////////////////////////////
    void SetSensorType(FIT_SENSOR_TYPE sensorType) {
        SetFieldENUMValue(0, sensorType, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of calibration_factor field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsCalibrationFactorValid() const {
        const Field *field = GetField(1);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns calibration_factor field
    // Comment: Calibration factor used to convert from raw ADC value to degrees, g, etc.
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT32 GetCalibrationFactor(void) const {
        return GetFieldUINT32Value(1, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set calibration_factor field
    // Comment: Calibration factor used to convert from raw ADC value to degrees, g, etc.
    ///////////////////////////////////////////////////////////////////////
    void SetCalibrationFactor(FIT_UINT32 calibrationFactor) {
        SetFieldUINT32Value(1, calibrationFactor, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of baro_cal_factor field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsBaroCalFactorValid() const {
        const Field *field = GetField(1);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        if (!CanSupportSubField(
                field,
                (FIT_UINT16) Profile::
                    ONE_D_SENSOR_CALIBRATION_MESG_CALIBRATION_FACTOR_FIELD_BARO_CAL_FACTOR)) {
            return FIT_FALSE;
        }

        return field->IsValueValid(
            0,
            (FIT_UINT16)
                Profile::ONE_D_SENSOR_CALIBRATION_MESG_CALIBRATION_FACTOR_FIELD_BARO_CAL_FACTOR);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns baro_cal_factor field
    // Units: Pa
    // Comment: Barometer calibration factor
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT32 GetBaroCalFactor(void) const {
        return GetFieldUINT32Value(
            1,
            0,
            (FIT_UINT16)
                Profile::ONE_D_SENSOR_CALIBRATION_MESG_CALIBRATION_FACTOR_FIELD_BARO_CAL_FACTOR);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set baro_cal_factor field
    // Units: Pa
    // Comment: Barometer calibration factor
    ///////////////////////////////////////////////////////////////////////
    void SetBaroCalFactor(FIT_UINT32 baroCalFactor) {
        SetFieldUINT32Value(
            1,
            baroCalFactor,
            0,
            (FIT_UINT16)
                Profile::ONE_D_SENSOR_CALIBRATION_MESG_CALIBRATION_FACTOR_FIELD_BARO_CAL_FACTOR);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of calibration_divisor field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsCalibrationDivisorValid() const {
        const Field *field = GetField(2);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns calibration_divisor field
    // Units: counts
    // Comment: Calibration factor divisor
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT32 GetCalibrationDivisor(void) const {
        return GetFieldUINT32Value(2, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set calibration_divisor field
    // Units: counts
    // Comment: Calibration factor divisor
    ///////////////////////////////////////////////////////////////////////
    void SetCalibrationDivisor(FIT_UINT32 calibrationDivisor) {
        SetFieldUINT32Value(2, calibrationDivisor, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of level_shift field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsLevelShiftValid() const {
        const Field *field = GetField(3);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns level_shift field
    // Comment: Level shift value used to shift the ADC value back into range
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT32 GetLevelShift(void) const {
        return GetFieldUINT32Value(3, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set level_shift field
    // Comment: Level shift value used to shift the ADC value back into range
    ///////////////////////////////////////////////////////////////////////
    void SetLevelShift(FIT_UINT32 levelShift) {
        SetFieldUINT32Value(3, levelShift, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of offset_cal field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsOffsetCalValid() const {
        const Field *field = GetField(4);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns offset_cal field
    // Comment: Internal Calibration factor
    ///////////////////////////////////////////////////////////////////////
    FIT_SINT32 GetOffsetCal(void) const {
        return GetFieldSINT32Value(4, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set offset_cal field
    // Comment: Internal Calibration factor
    ///////////////////////////////////////////////////////////////////////
    void SetOffsetCal(FIT_SINT32 offsetCal) {
        SetFieldSINT32Value(4, offsetCal, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }
};

} // namespace fit

#endif // !defined(FIT_ONE_D_SENSOR_CALIBRATION_MESG_HPP)
