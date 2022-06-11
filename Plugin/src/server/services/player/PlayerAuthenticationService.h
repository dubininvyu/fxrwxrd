//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Player.h"
#include "services.h"
#include "repositories.h"

class Player;

class PlayerAuthenticationService : public PlayerService {
private:
protected:
    PlayerRepository playerRepository;
public:
    PlayerAuthenticationService(Player* player);
    virtual ~PlayerAuthenticationService();

    bool isRegistered() const;
    unsigned int getUIDByPassword(const string& password) const;
};

