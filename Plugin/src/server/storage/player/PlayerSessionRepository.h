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
    PlayerSessionRepository(Player& player);
    virtual ~PlayerSessionRepository();

    unsigned long long createSession(const int online, const string& ip);
    bool updateSession(const PlayerDisconnectHandler::Reason reason);
};

