//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "PlayerRepository.h"
#include "PersonPosition.h"

class PlayerPositionRepository : public PlayerRepository {
private:
protected:
public:
    PlayerPositionRepository(Player& player);
    virtual ~PlayerPositionRepository();

    unsigned int createPosition();

    bool loadPosition();
    bool savePosition(PersonPosition* position);
};

