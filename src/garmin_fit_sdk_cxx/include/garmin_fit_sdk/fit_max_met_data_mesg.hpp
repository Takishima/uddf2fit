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

#if !defined(FIT_MAX_MET_DATA_MESG_HPP)
#    define FIT_MAX_MET_DATA_MESG_HPP

#    include "fit_mesg.hpp"

namespace fit {

class MaxMetDataMesg : public Mesg {
public:
    class FieldDefNum final {
    public:
        static const FIT_UINT8 UpdateTime = 0;
        static const FIT_UINT8 Vo2Max = 2;
        static const FIT_UINT8 Sport = 5;
        static const FIT_UINT8 SubSport = 6;
        static const FIT_UINT8 MaxMetCategory = 8;
        static const FIT_UINT8 CalibratedData = 9;
        static const FIT_UINT8 HrSource = 12;
        static const FIT_UINT8 SpeedSource = 13;
        static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    MaxMetDataMesg(void) : Mesg(Profile::MESG_MAX_MET_DATA) {}

    MaxMetDataMesg(const Mesg &mesg) : Mesg(mesg) {}

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of update_time field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsUpdateTimeValid() const {
        const Field *field = GetField(0);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns update_time field
    // Comment: Time maxMET and vo2 were calculated
    ///////////////////////////////////////////////////////////////////////
    FIT_DATE_TIME GetUpdateTime(void) const {
        return GetFieldUINT32Value(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set update_time field
    // Comment: Time maxMET and vo2 were calculated
    ///////////////////////////////////////////////////////////////////////
    void SetUpdateTime(FIT_DATE_TIME updateTime) {
        SetFieldUINT32Value(0, updateTime, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of vo2_max field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsVo2MaxValid() const {
        const Field *field = GetField(2);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns vo2_max field
    // Units: mL/kg/min
    ///////////////////////////////////////////////////////////////////////
    FIT_FLOAT32 GetVo2Max(void) const {
        return GetFieldFLOAT32Value(2, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set vo2_max field
    // Units: mL/kg/min
    ///////////////////////////////////////////////////////////////////////
    void SetVo2Max(FIT_FLOAT32 vo2Max) {
        SetFieldFLOAT32Value(2, vo2Max, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of sport field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsSportValid() const {
        const Field *field = GetField(5);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns sport field
    ///////////////////////////////////////////////////////////////////////
    FIT_SPORT GetSport(void) const {
        return GetFieldENUMValue(5, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set sport field
    ///////////////////////////////////////////////////////////////////////
    void SetSport(FIT_SPORT sport) {
        SetFieldENUMValue(5, sport, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of sub_sport field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsSubSportValid() const {
        const Field *field = GetField(6);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns sub_sport field
    ///////////////////////////////////////////////////////////////////////
    FIT_SUB_SPORT GetSubSport(void) const {
        return GetFieldENUMValue(6, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set sub_sport field
    ///////////////////////////////////////////////////////////////////////
    void SetSubSport(FIT_SUB_SPORT subSport) {
        SetFieldENUMValue(6, subSport, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of max_met_category field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsMaxMetCategoryValid() const {
        const Field *field = GetField(8);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns max_met_category field
    ///////////////////////////////////////////////////////////////////////
    FIT_MAX_MET_CATEGORY GetMaxMetCategory(void) const {
        return GetFieldENUMValue(8, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set max_met_category field
    ///////////////////////////////////////////////////////////////////////
    void SetMaxMetCategory(FIT_MAX_MET_CATEGORY maxMetCategory) {
        SetFieldENUMValue(8, maxMetCategory, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of calibrated_data field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsCalibratedDataValid() const {
        const Field *field = GetField(9);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns calibrated_data field
    // Comment: Indicates if calibrated data was used in the calculation
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetCalibratedData(void) const {
        return GetFieldENUMValue(9, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set calibrated_data field
    // Comment: Indicates if calibrated data was used in the calculation
    ///////////////////////////////////////////////////////////////////////
    void SetCalibratedData(FIT_BOOL calibratedData) {
        SetFieldENUMValue(9, calibratedData, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of hr_source field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsHrSourceValid() const {
        const Field *field = GetField(12);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns hr_source field
    // Comment: Indicates if the estimate was obtained using a chest strap or wrist heart rate
    ///////////////////////////////////////////////////////////////////////
    FIT_MAX_MET_HEART_RATE_SOURCE GetHrSource(void) const {
        return GetFieldENUMValue(12, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set hr_source field
    // Comment: Indicates if the estimate was obtained using a chest strap or wrist heart rate
    ///////////////////////////////////////////////////////////////////////
    void SetHrSource(FIT_MAX_MET_HEART_RATE_SOURCE hrSource) {
        SetFieldENUMValue(12, hrSource, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of speed_source field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsSpeedSourceValid() const {
        const Field *field = GetField(13);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns speed_source field
    // Comment: Indidcates if the estimate was obtained using onboard GPS or connected GPS
    ///////////////////////////////////////////////////////////////////////
    FIT_MAX_MET_SPEED_SOURCE GetSpeedSource(void) const {
        return GetFieldENUMValue(13, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set speed_source field
    // Comment: Indidcates if the estimate was obtained using onboard GPS or connected GPS
    ///////////////////////////////////////////////////////////////////////
    void SetSpeedSource(FIT_MAX_MET_SPEED_SOURCE speedSource) {
        SetFieldENUMValue(13, speedSource, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }
};

} // namespace fit

#endif // !defined(FIT_MAX_MET_DATA_MESG_HPP)
