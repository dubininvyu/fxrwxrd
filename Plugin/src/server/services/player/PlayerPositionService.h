//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Player.h"
#include "services.h"
#include "repositories.h"

class PlayerPositionService : public PlayerService {
private:
protected:
    PlayerPositionRepository positionRepository;
public:
    PlayerPositionService(Player* player);
    virtual ~PlayerPositionService();

    void savePosition();
};

