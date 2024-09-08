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

#if !defined(FIT_DIVE_GAS_MESG_HPP)
#    define FIT_DIVE_GAS_MESG_HPP

#    include "fit_mesg.hpp"

namespace fit {

class DiveGasMesg : public Mesg {
public:
    class FieldDefNum final {
    public:
        static const FIT_UINT8 MessageIndex = 254;
        static const FIT_UINT8 HeliumContent = 0;
        static const FIT_UINT8 OxygenContent = 1;
        static const FIT_UINT8 Status = 2;
        static const FIT_UINT8 Mode = 3;
        static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    DiveGasMesg(void) : Mesg(Profile::MESG_DIVE_GAS) {}

    DiveGasMesg(const Mesg &mesg) : Mesg(mesg) {}

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of message_index field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsMessageIndexValid() const {
        const Field *field = GetField(254);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns message_index field
    ///////////////////////////////////////////////////////////////////////
    FIT_MESSAGE_INDEX GetMessageIndex(void) const {
        return GetFieldUINT16Value(254, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set message_index field
    ///////////////////////////////////////////////////////////////////////
    void SetMessageIndex(FIT_MESSAGE_INDEX messageIndex) {
        SetFieldUINT16Value(254, messageIndex, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of helium_content field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsHeliumContentValid() const {
        const Field *field = GetField(0);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns helium_content field
    // Units: percent
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetHeliumContent(void) const {
        return GetFieldUINT8Value(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set helium_content field
    // Units: percent
    ///////////////////////////////////////////////////////////////////////
    void SetHeliumContent(FIT_UINT8 heliumContent) {
        SetFieldUINT8Value(0, heliumContent, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of oxygen_content field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsOxygenContentValid() const {
        const Field *field = GetField(1);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns oxygen_content field
    // Units: percent
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetOxygenContent(void) const {
        return GetFieldUINT8Value(1, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set oxygen_content field
    // Units: percent
    ///////////////////////////////////////////////////////////////////////
    void SetOxygenContent(FIT_UINT8 oxygenContent) {
        SetFieldUINT8Value(1, oxygenContent, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of status field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsStatusValid() const {
        const Field *field = GetField(2);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns status field
    ///////////////////////////////////////////////////////////////////////
    FIT_DIVE_GAS_STATUS GetStatus(void) const {
        return GetFieldENUMValue(2, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set status field
    ///////////////////////////////////////////////////////////////////////
    void SetStatus(FIT_DIVE_GAS_STATUS status) {
        SetFieldENUMValue(2, status, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of mode field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsModeValid() const {
        const Field *field = GetField(3);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns mode field
    ///////////////////////////////////////////////////////////////////////
    FIT_DIVE_GAS_MODE GetMode(void) const {
        return GetFieldENUMValue(3, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set mode field
    ///////////////////////////////////////////////////////////////////////
    void SetMode(FIT_DIVE_GAS_MODE mode) {
        SetFieldENUMValue(3, mode, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }
};

} // namespace fit

#endif // !defined(FIT_DIVE_GAS_MESG_HPP)
