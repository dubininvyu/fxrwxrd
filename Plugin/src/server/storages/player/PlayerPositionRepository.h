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
    PlayerPositionRepository(Player* player);
    virtual ~PlayerPositionRepository();

    /* main */
    virtual bool preload();
    virtual unsigned int save();
    virtual unsigned int load();
    virtual unsigned int block();
    virtual unsigned int create();
};

