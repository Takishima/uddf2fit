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

#if !defined(FIT_CLIMB_PRO_MESG_HPP)
#    define FIT_CLIMB_PRO_MESG_HPP

#    include "fit_mesg.hpp"

namespace fit {

class ClimbProMesg : public Mesg {
public:
    class FieldDefNum final {
    public:
        static const FIT_UINT8 Timestamp = 253;
        static const FIT_UINT8 PositionLat = 0;
        static const FIT_UINT8 PositionLong = 1;
        static const FIT_UINT8 ClimbProEvent = 2;
        static const FIT_UINT8 ClimbNumber = 3;
        static const FIT_UINT8 ClimbCategory = 4;
        static const FIT_UINT8 CurrentDist = 5;
        static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    ClimbProMesg(void) : Mesg(Profile::MESG_CLIMB_PRO) {}

    ClimbProMesg(const Mesg &mesg) : Mesg(mesg) {}

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
    // Checks the validity of position_lat field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsPositionLatValid() const {
        const Field *field = GetField(0);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns position_lat field
    // Units: semicircles
    ///////////////////////////////////////////////////////////////////////
    FIT_SINT32 GetPositionLat(void) const {
        return GetFieldSINT32Value(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set position_lat field
    // Units: semicircles
    ///////////////////////////////////////////////////////////////////////
    void SetPositionLat(FIT_SINT32 positionLat) {
        SetFieldSINT32Value(0, positionLat, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of position_long field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsPositionLongValid() const {
        const Field *field = GetField(1);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns position_long field
    // Units: semicircles
    ///////////////////////////////////////////////////////////////////////
    FIT_SINT32 GetPositionLong(void) const {
        return GetFieldSINT32Value(1, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set position_long field
    // Units: semicircles
    ///////////////////////////////////////////////////////////////////////
    void SetPositionLong(FIT_SINT32 positionLong) {
        SetFieldSINT32Value(1, positionLong, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of climb_pro_event field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsClimbProEventValid() const {
        const Field *field = GetField(2);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns climb_pro_event field
    ///////////////////////////////////////////////////////////////////////
    FIT_CLIMB_PRO_EVENT GetClimbProEvent(void) const {
        return GetFieldENUMValue(2, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set climb_pro_event field
    ///////////////////////////////////////////////////////////////////////
    void SetClimbProEvent(FIT_CLIMB_PRO_EVENT climbProEvent) {
        SetFieldENUMValue(2, climbProEvent, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of climb_number field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsClimbNumberValid() const {
        const Field *field = GetField(3);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns climb_number field
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT16 GetClimbNumber(void) const {
        return GetFieldUINT16Value(3, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set climb_number field
    ///////////////////////////////////////////////////////////////////////
    void SetClimbNumber(FIT_UINT16 climbNumber) {
        SetFieldUINT16Value(3, climbNumber, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of climb_category field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsClimbCategoryValid() const {
        const Field *field = GetField(4);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns climb_category field
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetClimbCategory(void) const {
        return GetFieldUINT8Value(4, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set climb_category field
    ///////////////////////////////////////////////////////////////////////
    void SetClimbCategory(FIT_UINT8 climbCategory) {
        SetFieldUINT8Value(4, climbCategory, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of current_dist field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsCurrentDistValid() const {
        const Field *field = GetField(5);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns current_dist field
    // Units: m
    ///////////////////////////////////////////////////////////////////////
    FIT_FLOAT32 GetCurrentDist(void) const {
        return GetFieldFLOAT32Value(5, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set current_dist field
    // Units: m
    ///////////////////////////////////////////////////////////////////////
    void SetCurrentDist(FIT_FLOAT32 currentDist) {
        SetFieldFLOAT32Value(5, currentDist, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }
};

} // namespace fit

#endif // !defined(FIT_CLIMB_PRO_MESG_HPP)
