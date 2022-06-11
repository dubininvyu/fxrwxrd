//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Player.h"
#include "PlayerService.h"
#include "PlayerRepository.h"

class PlayerAuthorizationService : public PlayerService {
private:
protected:
    PlayerRepository playerRepository;
public:
    PlayerAuthorizationService(Player* player);
    virtual ~PlayerAuthorizationService();

    bool beginPasswordAuthorization();
    bool endAuthorization();
};

