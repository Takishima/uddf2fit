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

#if !defined(FIT_HSA_STRESS_DATA_MESG_HPP)
#    define FIT_HSA_STRESS_DATA_MESG_HPP

#    include "fit_mesg.hpp"

namespace fit {

class HsaStressDataMesg : public Mesg {
public:
    class FieldDefNum final {
    public:
        static const FIT_UINT8 Timestamp = 253;
        static const FIT_UINT8 ProcessingInterval = 0;
        static const FIT_UINT8 StressLevel = 1;
        static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    HsaStressDataMesg(void) : Mesg(Profile::MESG_HSA_STRESS_DATA) {}

    HsaStressDataMesg(const Mesg &mesg) : Mesg(mesg) {}

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
    // Returns number of stress_level
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumStressLevel(void) const {
        return GetFieldNumValues(1, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of stress_level field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsStressLevelValid(FIT_UINT8 index) const {
        const Field *field = GetField(1);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns stress_level field
    // Units: s
    // Comment: Stress Level ( 0 - 100 ) -300 indicates invalid -200 indicates large motion -100
    // indicates off wrist
    ///////////////////////////////////////////////////////////////////////
    FIT_SINT8 GetStressLevel(FIT_UINT8 index) const {
        return GetFieldSINT8Value(1, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set stress_level field
    // Units: s
    // Comment: Stress Level ( 0 - 100 ) -300 indicates invalid -200 indicates large motion -100
    // indicates off wrist
    ///////////////////////////////////////////////////////////////////////
    void SetStressLevel(FIT_UINT8 index, FIT_SINT8 stressLevel) {
        SetFieldSINT8Value(1, stressLevel, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }
};

} // namespace fit

#endif // !defined(FIT_HSA_STRESS_DATA_MESG_HPP)
