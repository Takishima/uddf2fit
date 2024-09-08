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

#if !defined(FIT_HSA_WRIST_TEMPERATURE_DATA_MESG_LISTENER_HPP)
#    define FIT_HSA_WRIST_TEMPERATURE_DATA_MESG_LISTENER_HPP

#    include "fit_hsa_wrist_temperature_data_mesg.hpp"

namespace fit {

class HsaWristTemperatureDataMesgListener {
public:
    virtual ~HsaWristTemperatureDataMesgListener() {}
    virtual void OnMesg(HsaWristTemperatureDataMesg &mesg) = 0;
};

} // namespace fit

#endif // !defined(FIT_HSA_WRIST_TEMPERATURE_DATA_MESG_LISTENER_HPP)
