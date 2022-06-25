//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Player.h"
#include "PlayerService.h"
#include "PlayerRepository.h"

#include "machines_events.h"

typedef Error::ErrorType ErrorType;

class PlayerAuthorizationService : public PlayerService {
private:
protected:
    PlayerRepository playerRepository;
public:
    PlayerAuthorizationService(Player* player);
    virtual ~PlayerAuthorizationService();

    bool beginLocale();
    bool beginPassword();
    bool authorize();

    bool stop(const ErrorType error);
};

