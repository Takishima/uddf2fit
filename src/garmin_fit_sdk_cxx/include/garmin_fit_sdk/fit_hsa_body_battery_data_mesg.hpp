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

#if !defined(FIT_HSA_BODY_BATTERY_DATA_MESG_HPP)
#    define FIT_HSA_BODY_BATTERY_DATA_MESG_HPP

#    include "fit_mesg.hpp"

namespace fit {

class HsaBodyBatteryDataMesg : public Mesg {
public:
    class FieldDefNum final {
    public:
        static const FIT_UINT8 Timestamp = 253;
        static const FIT_UINT8 ProcessingInterval = 0;
        static const FIT_UINT8 Level = 1;
        static const FIT_UINT8 Charged = 2;
        static const FIT_UINT8 Uncharged = 3;
        static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    HsaBodyBatteryDataMesg(void) : Mesg(Profile::MESG_HSA_BODY_BATTERY_DATA) {}

    HsaBodyBatteryDataMesg(const Mesg &mesg) : Mesg(mesg) {}

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
    ///////////////////////////////////////////////////////////////////////
    FIT_DATE_TIME GetTimestamp(void) const {
        return GetFieldUINT32Value(253, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set timestamp field
    // Units: s
    ///////////////////////////////////////////////////////////////////////
    void SetTimestamp(FIT_DATE_TIME timestamp) {
        SetFieldUINT32Value(253, timestamp, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of processing_interval field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsProcessingIntervalValid() const {
        const Field *field = GetField(0);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns processing_interval field
    // Units: s
    // Comment: Processing interval length in seconds
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT16 GetProcessingInterval(void) const {
        return GetFieldUINT16Value(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set processing_interval field
    // Units: s
    // Comment: Processing interval length in seconds
    ///////////////////////////////////////////////////////////////////////
    void SetProcessingInterval(FIT_UINT16 processingInterval) {
        SetFieldUINT16Value(0, processingInterval, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of level
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumLevel(void) const {
        return GetFieldNumValues(1, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of level field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsLevelValid(FIT_UINT8 index) const {
        const Field *field = GetField(1);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns level field
    // Units: percent
    // Comment: Body battery level
    ///////////////////////////////////////////////////////////////////////
    FIT_SINT8 GetLevel(FIT_UINT8 index) const {
        return GetFieldSINT8Value(1, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set level field
    // Units: percent
    // Comment: Body battery level
    ///////////////////////////////////////////////////////////////////////
    void SetLevel(FIT_UINT8 index, FIT_SINT8 level) {
        SetFieldSINT8Value(1, level, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of charged
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumCharged(void) const {
        return GetFieldNumValues(2, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of charged field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsChargedValid(FIT_UINT8 index) const {
        const Field *field = GetField(2);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns charged field
    // Comment: Body battery charged value
    ///////////////////////////////////////////////////////////////////////
    FIT_SINT16 GetCharged(FIT_UINT8 index) const {
        return GetFieldSINT16Value(2, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set charged field
    // Comment: Body battery charged value
    ///////////////////////////////////////////////////////////////////////
    void SetCharged(FIT_UINT8 index, FIT_SINT16 charged) {
        SetFieldSINT16Value(2, charged, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of uncharged
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumUncharged(void) const {
        return GetFieldNumValues(3, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of uncharged field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsUnchargedValid(FIT_UINT8 index) const {
        const Field *field = GetField(3);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns uncharged field
    // Comment: Body battery uncharged value
    ///////////////////////////////////////////////////////////////////////
    FIT_SINT16 GetUncharged(FIT_UINT8 index) const {
        return GetFieldSINT16Value(3, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set uncharged field
    // Comment: Body battery uncharged value
    ///////////////////////////////////////////////////////////////////////
    void SetUncharged(FIT_UINT8 index, FIT_SINT16 uncharged) {
        SetFieldSINT16Value(3, uncharged, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }
};

} // namespace fit

#endif // !defined(FIT_HSA_BODY_BATTERY_DATA_MESG_HPP)
