//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "PlayerEventHandler.h"

class PlayerSpawnHandler : public PlayerEventHandler {
private:
protected:
public:
    PlayerSpawnHandler(Player& player);
    virtual ~PlayerSpawnHandler();

    virtual bool execute();
};