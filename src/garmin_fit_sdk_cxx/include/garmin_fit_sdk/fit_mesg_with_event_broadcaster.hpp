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

#if !defined(FIT_MESG_WITH_EVENT_BROADCASTER_HPP)
#    define FIT_MESG_WITH_EVENT_BROADCASTER_HPP

#    include <list>
#    include <vector>

#    include "fit_mesg_with_event.hpp"
#    include "fit_mesg_with_event_listener.hpp"

namespace fit {

class MesgWithEventBroadcaster : public MesgWithEventListener {
public:
    MesgWithEventBroadcaster(void);
    void AddListener(MesgWithEventListener &mesgObserver);
    void RemoveListener(MesgWithEventListener &mesgObserver);
    void OnMesg(MesgWithEvent &mesg);

private:
    void Broadcast(MesgWithEvent &mesg);

    std::vector<MesgWithEventListener *> listeners;
    std::vector<std::list<MesgWithEvent *>> startedEvents;
};

} // namespace fit

#endif // !defined(FIT_MESG_WITH_EVENT_BROADCASTER_HPP)
