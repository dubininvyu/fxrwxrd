//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "PlayerEventHandler.h"

class PlayerRequestClassHandler : public PlayerEventHandler {
private:
protected:
    unsigned int classID;
public:
    PlayerRequestClassHandler(Player* player, unsigned int classID);
    virtual ~PlayerRequestClassHandler();

    virtual bool execute();
};