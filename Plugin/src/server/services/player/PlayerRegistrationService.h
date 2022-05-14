//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Player.h"
#include "PlayerService.h"
#include "PlayerRepository.h"

class PlayerRegistrationService : public PlayerService {
private:
protected:
    PlayerRepository playerRepository;
public:
    PlayerRegistrationService(Player& player);
    virtual ~PlayerRegistrationService();

    bool startRegistration();
    bool finishRegistration(const string& password, Player::Sex sex);
};

