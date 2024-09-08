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

#if !defined(FIT_RAW_BBI_MESG_HPP)
#    define FIT_RAW_BBI_MESG_HPP

#    include "fit_mesg.hpp"

namespace fit {

class RawBbiMesg : public Mesg {
public:
    class FieldDefNum final {
    public:
        static const FIT_UINT8 Timestamp = 253;
        static const FIT_UINT8 TimestampMs = 0;
        static const FIT_UINT8 Data = 1;
        static const FIT_UINT8 Time = 2;
        static const FIT_UINT8 Quality = 3;
        static const FIT_UINT8 Gap = 4;
        static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    RawBbiMesg(void) : Mesg(Profile::MESG_RAW_BBI) {}

    RawBbiMesg(const Mesg &mesg) : Mesg(mesg) {}

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
    ///////////////////////////////////////////////////////////////////////
    FIT_DATE_TIME GetTimestamp(void) const {
        return GetFieldUINT32Value(253, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set timestamp field
    ///////////////////////////////////////////////////////////////////////
    void SetTimestamp(FIT_DATE_TIME timestamp) {
        SetFieldUINT32Value(253, timestamp, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of timestamp_ms field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsTimestampMsValid() const {
        const Field *field = GetField(0);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns timestamp_ms field
    // Units: ms
    // Comment: ms since last overnight_raw_bbi message
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT16 GetTimestampMs(void) const {
        return GetFieldUINT16Value(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set timestamp_ms field
    // Units: ms
    // Comment: ms since last overnight_raw_bbi message
    ///////////////////////////////////////////////////////////////////////
    void SetTimestampMs(FIT_UINT16 timestampMs) {
        SetFieldUINT16Value(0, timestampMs, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of data
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumData(void) const {
        return GetFieldNumValues(1, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of data field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsDataValid(FIT_UINT8 index) const {
        const Field *field = GetField(1);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns data field
    // Comment: 1 bit for gap indicator, 1 bit for quality indicator, and 14 bits for Beat-to-Beat
    // interval values in whole-integer millisecond resolution
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT16 GetData(FIT_UINT8 index) const {
        return GetFieldUINT16Value(1, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set data field
    // Comment: 1 bit for gap indicator, 1 bit for quality indicator, and 14 bits for Beat-to-Beat
    // interval values in whole-integer millisecond resolution
    ///////////////////////////////////////////////////////////////////////
    void SetData(FIT_UINT8 index, FIT_UINT16 data) {
        SetFieldUINT16Value(1, data, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of time
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumTime(void) const {
        return GetFieldNumValues(2, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of time field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsTimeValid(FIT_UINT8 index) const {
        const Field *field = GetField(2);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns time field
    // Units: ms
    // Comment: Array of millisecond times between beats
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT16 GetTime(FIT_UINT8 index) const {
        return GetFieldUINT16Value(2, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set time field
    // Units: ms
    // Comment: Array of millisecond times between beats
    ///////////////////////////////////////////////////////////////////////
    void SetTime(FIT_UINT8 index, FIT_UINT16 time) {
        SetFieldUINT16Value(2, time, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of quality
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumQuality(void) const {
        return GetFieldNumValues(3, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of quality field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsQualityValid(FIT_UINT8 index) const {
        const Field *field = GetField(3);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns quality field
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetQuality(FIT_UINT8 index) const {
        return GetFieldUINT8Value(3, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set quality field
    ///////////////////////////////////////////////////////////////////////
    void SetQuality(FIT_UINT8 index, FIT_UINT8 quality) {
        SetFieldUINT8Value(3, quality, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of gap
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumGap(void) const { return GetFieldNumValues(4, FIT_SUBFIELD_INDEX_MAIN_FIELD); }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of gap field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsGapValid(FIT_UINT8 index) const {
        const Field *field = GetField(4);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns gap field
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetGap(FIT_UINT8 index) const {
        return GetFieldUINT8Value(4, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set gap field
    ///////////////////////////////////////////////////////////////////////
    void SetGap(FIT_UINT8 index, FIT_UINT8 gap) {
        SetFieldUINT8Value(4, gap, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }
};

} // namespace fit

#endif // !defined(FIT_RAW_BBI_MESG_HPP)
