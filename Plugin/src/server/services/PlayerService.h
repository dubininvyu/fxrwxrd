//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Service.h"

class Player;

class PlayerService : public Service {
private:
protected:
    Player* player;

    unsigned int stage;

    PlayerService(Player* player);
public:
    virtual ~PlayerService() = 0;
};

