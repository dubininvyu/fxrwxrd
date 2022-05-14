//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "Player.h"
#include "EventHandler.h"

class PlayerEventHandler : public EventHandler {
private:
protected:
    Player& player;
    PlayerEventHandler(Player& player);
public:
    virtual ~PlayerEventHandler() = 0;
};

