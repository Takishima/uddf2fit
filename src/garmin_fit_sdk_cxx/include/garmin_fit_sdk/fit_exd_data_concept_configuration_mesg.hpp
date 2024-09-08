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

#if !defined(FIT_EXD_DATA_CONCEPT_CONFIGURATION_MESG_HPP)
#    define FIT_EXD_DATA_CONCEPT_CONFIGURATION_MESG_HPP

#    include "fit_mesg.hpp"

namespace fit {

class ExdDataConceptConfigurationMesg : public Mesg {
public:
    class FieldDefNum final {
    public:
        static const FIT_UINT8 ScreenIndex = 0;
        static const FIT_UINT8 ConceptField = 1;
        static const FIT_UINT8 FieldId = 2;
        static const FIT_UINT8 ConceptIndex = 3;
        static const FIT_UINT8 DataPage = 4;
        static const FIT_UINT8 ConceptKey = 5;
        static const FIT_UINT8 Scaling = 6;
        static const FIT_UINT8 DataUnits = 8;
        static const FIT_UINT8 Qualifier = 9;
        static const FIT_UINT8 Descriptor = 10;
        static const FIT_UINT8 IsSigned = 11;
        static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    ExdDataConceptConfigurationMesg(void) : Mesg(Profile::MESG_EXD_DATA_CONCEPT_CONFIGURATION) {}

    ExdDataConceptConfigurationMesg(const Mesg &mesg) : Mesg(mesg) {}

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of screen_index field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsScreenIndexValid() const {
        const Field *field = GetField(0);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns screen_index field
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetScreenIndex(void) const {
        return GetFieldUINT8Value(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set screen_index field
    ///////////////////////////////////////////////////////////////////////
    void SetScreenIndex(FIT_UINT8 screenIndex) {
        SetFieldUINT8Value(0, screenIndex, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of concept_field field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsConceptFieldValid() const {
        const Field *field = GetField(1);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns concept_field field
    ///////////////////////////////////////////////////////////////////////
    FIT_BYTE GetConceptField(void) const {
        return GetFieldBYTEValue(1, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set concept_field field
    ///////////////////////////////////////////////////////////////////////
    void SetConceptField(FIT_BYTE conceptField) {
        SetFieldBYTEValue(1, conceptField, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of field_id field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsFieldIdValid() const {
        const Field *field = GetField(2);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns field_id field
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetFieldId(void) const {
        return GetFieldUINT8Value(2, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set field_id field
    ///////////////////////////////////////////////////////////////////////
    void SetFieldId(FIT_UINT8 fieldId) {
        SetFieldUINT8Value(2, fieldId, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of concept_index field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsConceptIndexValid() const {
        const Field *field = GetField(3);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns concept_index field
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetConceptIndex(void) const {
        return GetFieldUINT8Value(3, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set concept_index field
    ///////////////////////////////////////////////////////////////////////
    void SetConceptIndex(FIT_UINT8 conceptIndex) {
        SetFieldUINT8Value(3, conceptIndex, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of data_page field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsDataPageValid() const {
        const Field *field = GetField(4);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns data_page field
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetDataPage(void) const {
        return GetFieldUINT8Value(4, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set data_page field
    ///////////////////////////////////////////////////////////////////////
    void SetDataPage(FIT_UINT8 dataPage) {
        SetFieldUINT8Value(4, dataPage, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of concept_key field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsConceptKeyValid() const {
        const Field *field = GetField(5);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns concept_key field
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetConceptKey(void) const {
        return GetFieldUINT8Value(5, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set concept_key field
    ///////////////////////////////////////////////////////////////////////
    void SetConceptKey(FIT_UINT8 conceptKey) {
        SetFieldUINT8Value(5, conceptKey, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of scaling field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsScalingValid() const {
        const Field *field = GetField(6);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns scaling field
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetScaling(void) const {
        return GetFieldUINT8Value(6, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set scaling field
    ///////////////////////////////////////////////////////////////////////
    void SetScaling(FIT_UINT8 scaling) {
        SetFieldUINT8Value(6, scaling, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of data_units field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsDataUnitsValid() const {
        const Field *field = GetField(8);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns data_units field
    ///////////////////////////////////////////////////////////////////////
    FIT_EXD_DATA_UNITS GetDataUnits(void) const {
        return GetFieldENUMValue(8, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set data_units field
    ///////////////////////////////////////////////////////////////////////
    void SetDataUnits(FIT_EXD_DATA_UNITS dataUnits) {
        SetFieldENUMValue(8, dataUnits, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of qualifier field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsQualifierValid() const {
        const Field *field = GetField(9);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns qualifier field
    ///////////////////////////////////////////////////////////////////////
    FIT_EXD_QUALIFIERS GetQualifier(void) const {
        return GetFieldENUMValue(9, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set qualifier field
    ///////////////////////////////////////////////////////////////////////
    void SetQualifier(FIT_EXD_QUALIFIERS qualifier) {
        SetFieldENUMValue(9, qualifier, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of descriptor field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsDescriptorValid() const {
        const Field *field = GetField(10);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns descriptor field
    ///////////////////////////////////////////////////////////////////////
    FIT_EXD_DESCRIPTORS GetDescriptor(void) const {
        return GetFieldENUMValue(10, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set descriptor field
    ///////////////////////////////////////////////////////////////////////
    void SetDescriptor(FIT_EXD_DESCRIPTORS descriptor) {
        SetFieldENUMValue(10, descriptor, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of is_signed field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsIsSignedValid() const {
        const Field *field = GetField(11);
        if (FIT_NULL == field) {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns is_signed field
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetIsSigned(void) const {
        return GetFieldENUMValue(11, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set is_signed field
    ///////////////////////////////////////////////////////////////////////
    void SetIsSigned(FIT_BOOL isSigned) {
        SetFieldENUMValue(11, isSigned, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }
};

} // namespace fit

#endif // !defined(FIT_EXD_DATA_CONCEPT_CONFIGURATION_MESG_HPP)
