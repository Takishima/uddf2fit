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

#include "fit_developer_field_definition.hpp"

#include <ostream>

#include "fit_developer_field.hpp"

namespace fit {

DeveloperFieldDefinition::DeveloperFieldDefinition()
    : num(FIT_FIELD_NUM_INVALID), size(0), developerDataIndex(FIT_UINT8_INVALID), mesg(nullptr),
      developer(nullptr) {}

DeveloperFieldDefinition::DeveloperFieldDefinition(const DeveloperFieldDefinition &other)
    : num(other.num), size(other.size), developerDataIndex(other.developerDataIndex),
      mesg(nullptr), developer(nullptr) {
    if (nullptr != other.mesg) {
        mesg = new FieldDescriptionMesg(*other.mesg);
    }

    if (nullptr != other.developer) {
        developer = new DeveloperDataIdMesg(*other.developer);
    }
}

DeveloperFieldDefinition::DeveloperFieldDefinition(FIT_UINT8 fieldNum,
                                                   FIT_UINT8 size,
                                                   FIT_UINT8 developerDataIndex)
    : num(fieldNum), size(size), developerDataIndex(developerDataIndex), mesg(nullptr),
      developer(nullptr) {}

DeveloperFieldDefinition::DeveloperFieldDefinition(const FieldDescriptionMesg &desc,
                                                   const DeveloperDataIdMesg &developer,
                                                   FIT_UINT8 size)
    : num(desc.GetFieldDefinitionNumber()), size(size),
      developerDataIndex(desc.GetDeveloperDataIndex()), mesg(new FieldDescriptionMesg(desc)),
      developer(new DeveloperDataIdMesg(developer)) {}

DeveloperFieldDefinition::DeveloperFieldDefinition(const DeveloperField &field)
    : DeveloperFieldDefinition(field.GetDefinition()) {
    size = field.GetSize();
}

DeveloperFieldDefinition::~DeveloperFieldDefinition() {
    if (nullptr != mesg) {
        delete mesg;
        mesg = nullptr;
    }

    if (nullptr != developer) {
        delete developer;
        developer = nullptr;
    }
}

FIT_BOOL DeveloperFieldDefinition::IsDefined() const {
    return nullptr != mesg && nullptr != developer;
}

FIT_UINT8 DeveloperFieldDefinition::GetNum() const { return num; }

FIT_UINT8 DeveloperFieldDefinition::GetSize() const { return size; }

FIT_UINT8 DeveloperFieldDefinition::GetType() const {
    if (IsDefined()) {
        return mesg->GetFitBaseTypeId();
    }

    return FIT_BASE_TYPE_UINT8;
}

FIT_UINT8 DeveloperFieldDefinition::GetDeveloperDataIndex() const { return developerDataIndex; }

const FieldDescriptionMesg &DeveloperFieldDefinition::GetDescription() const { return *mesg; }

const DeveloperDataIdMesg &DeveloperFieldDefinition::GetDeveloper() const { return *developer; }

FIT_BOOL DeveloperFieldDefinition::operator==(const DeveloperFieldDefinition &field) const {
    if (num != field.num)
        return FIT_FALSE;

    if (developerDataIndex != field.developerDataIndex)
        return FIT_FALSE;

    return FIT_TRUE;
}

FIT_BOOL DeveloperFieldDefinition::operator!=(const DeveloperFieldDefinition &field) const {
    return !(*this == field);
}

FIT_UINT8 DeveloperFieldDefinition::Write(std::ostream &file) const {
    file.put(num);
    file.put(size);
    file.put(developerDataIndex);

    return 3;
}

DeveloperFieldDefinition &
DeveloperFieldDefinition::operator=(const DeveloperFieldDefinition &other) {
    if (this != &other) {
        num = other.num;
        size = other.size;
        developerDataIndex = other.developerDataIndex;

        if (other.mesg != nullptr) {
            if (mesg != nullptr) {
                delete mesg;
            }
            mesg = new FieldDescriptionMesg(*other.mesg);
        }

        if (other.developer != nullptr) {
            if (developer != nullptr) {
                delete developer;
            };
            developer = new DeveloperDataIdMesg(*other.developer);
        }
    }

    return *this;
}

} // namespace fit
