//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "PlayerEventHandler.h"

class PlayerDisconnectHandler : public PlayerEventHandler {
public:
    enum Reason {
        REASON_NONE = 0, // player is online

        REASON_ABORTED,
        REASON_EXITED,
        REASON_KICKED
    };
private:
protected:
    Reason reason;
public:
    PlayerDisconnectHandler(Player* player, Reason reason);
    virtual ~PlayerDisconnectHandler();

    virtual bool execute();
};