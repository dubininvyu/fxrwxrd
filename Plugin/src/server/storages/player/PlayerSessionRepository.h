//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "PlayerRepository.h"
#include "PlayerDisconnectHandler.h"

class PlayerSessionRepository : public PlayerRepository {
private:
protected:
public:
    PlayerSessionRepository(Player* player);
    virtual ~PlayerSessionRepository();

    /* main */
    virtual bool preload();

    virtual unsigned int load();
    virtual unsigned int block();
    virtual unsigned int update(const PlayerDisconnectHandler::Reason reason);
    virtual unsigned int create();

};

