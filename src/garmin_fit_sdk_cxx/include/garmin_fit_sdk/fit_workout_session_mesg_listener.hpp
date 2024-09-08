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

#if !defined(FIT_WORKOUT_SESSION_MESG_LISTENER_HPP)
#    define FIT_WORKOUT_SESSION_MESG_LISTENER_HPP

#    include "fit_workout_session_mesg.hpp"

namespace fit {

class WorkoutSessionMesgListener {
public:
    virtual ~WorkoutSessionMesgListener() {}
    virtual void OnMesg(WorkoutSessionMesg &mesg) = 0;
};

} // namespace fit

#endif // !defined(FIT_WORKOUT_SESSION_MESG_LISTENER_HPP)
