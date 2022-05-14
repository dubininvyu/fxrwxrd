//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Player.h"
#include "PlayerService.h"
#include "PlayerRepository.h"

class PlayerAuthenticationService : public PlayerService {
private:
protected:
    PlayerRepository playerRepository;
public:
    PlayerAuthenticationService(Player& player);
    virtual ~PlayerAuthenticationService();

    bool startAuthentication();
    bool finishAuthentication();
};

