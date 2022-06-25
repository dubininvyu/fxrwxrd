//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Player.h"

#include "PersonSex.h"

#include "services.h"
#include "repositories.h"
#include "machines_events.h"

typedef Error::ErrorType ErrorType;

class PlayerRegistrationService : public PlayerService {
private:
protected:
    PlayerRepository playerRepository;
public:
    PlayerRegistrationService(Player* player);
    virtual ~PlayerRegistrationService();

    bool startLocaleEntering();
    bool startPasswordEntering();
    bool startSexEntering();
    bool startAgeEntering();
    bool stop(const ErrorType error); // if it's an error

    bool registerAccount();
};

