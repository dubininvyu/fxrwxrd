//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "EventHandler.h"

class Player;

class PlayerEventHandler : public EventHandler {
private:
protected:
    Player* player;
    PlayerEventHandler(Player* player);
public:
    virtual ~PlayerEventHandler() = 0;
};

