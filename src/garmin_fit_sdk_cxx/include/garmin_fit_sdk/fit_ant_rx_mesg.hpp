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

#if !defined(FIT_ANT_RX_MESG_HPP)
#    define FIT_ANT_RX_MESG_HPP

#    include "fit_mesg.hpp"

namespace fit {

class AntRxMesg : public Mesg {
public:
    class FieldDefNum final {
    public:
        static const FIT_UINT8 Timestamp = 253;
        static const FIT_UINT8 FractionalTimestamp = 0;
        static const FIT_UINT8 MesgId = 1;
        static const FIT_UINT8 MesgData = 2;
        static const FIT_UINT8 ChannelNumber = 3;
        static const FIT_UINT8 Data = 4;
        static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    AntRxMesg(void) : Mesg(Profile::MESG_ANT_RX) {}

    AntRxMesg(const Mesg &mesg) : Mesg(mesg) {}

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
    // Checks the validity of fractional_timestamp field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsFractionalTimestampValid() const {
        const Field *field = GetField(0);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns fractional_timestamp field
    // Units: s
    ///////////////////////////////////////////////////////////////////////
    FIT_FLOAT32 GetFractionalTimestamp(void) const {
        return GetFieldFLOAT32Value(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set fractional_timestamp field
    // Units: s
    ///////////////////////////////////////////////////////////////////////
    void SetFractionalTimestamp(FIT_FLOAT32 fractionalTimestamp) {
        SetFieldFLOAT32Value(0, fractionalTimestamp, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of mesg_id field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsMesgIdValid() const {
        const Field *field = GetField(1);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns mesg_id field
    ///////////////////////////////////////////////////////////////////////
    FIT_BYTE GetMesgId(void) const {
        return GetFieldBYTEValue(1, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set mesg_id field
    ///////////////////////////////////////////////////////////////////////
    void SetMesgId(FIT_BYTE mesgId) {
        SetFieldBYTEValue(1, mesgId, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of mesg_data
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumMesgData(void) const {
        return GetFieldNumValues(2, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of mesg_data field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsMesgDataValid(FIT_UINT8 index) const {
        const Field *field = GetField(2);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns mesg_data field
    ///////////////////////////////////////////////////////////////////////
    FIT_BYTE GetMesgData(FIT_UINT8 index) const {
        return GetFieldBYTEValue(2, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set mesg_data field
    ///////////////////////////////////////////////////////////////////////
    void SetMesgData(FIT_UINT8 index, FIT_BYTE mesgData) {
        SetFieldBYTEValue(2, mesgData, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of channel_number field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsChannelNumberValid() const {
        const Field *field = GetField(3);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns channel_number field
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetChannelNumber(void) const {
        return GetFieldUINT8Value(3, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set channel_number field
    ///////////////////////////////////////////////////////////////////////
    void SetChannelNumber(FIT_UINT8 channelNumber) {
        SetFieldUINT8Value(3, channelNumber, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of data
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumData(void) const {
        return GetFieldNumValues(4, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of data field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsDataValid(FIT_UINT8 index) const {
        const Field *field = GetField(4);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns data field
    ///////////////////////////////////////////////////////////////////////
    FIT_BYTE GetData(FIT_UINT8 index) const {
        return GetFieldBYTEValue(4, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set data field
    ///////////////////////////////////////////////////////////////////////
    void SetData(FIT_UINT8 index, FIT_BYTE data) {
        SetFieldBYTEValue(4, data, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }
};

} // namespace fit

#endif // !defined(FIT_ANT_RX_MESG_HPP)
