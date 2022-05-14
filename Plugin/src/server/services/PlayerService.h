//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Service.h"
#include "Player.h"

class PlayerService : public Service {
private:
protected:
    Player& player;

    PlayerService(Player& player);
public:
    virtual ~PlayerService() = 0;
};

