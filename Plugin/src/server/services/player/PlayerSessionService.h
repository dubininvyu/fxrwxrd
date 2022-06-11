//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Player.h"
#include "PlayerService.h"
#include "PlayerSessionRepository.h"

class PlayerSessionService : public PlayerService {
private:
protected:
    PlayerSessionRepository sessionRepository;
public:
    PlayerSessionService(Player* player);
    virtual ~PlayerSessionService();

    void createConnectSession();
    void createDisconnectSession(PlayerDisconnectHandler::Reason reason);
};

