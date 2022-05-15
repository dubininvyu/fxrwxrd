//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Player.h"

#include "PersonSex.h"

#include "services.h"
#include "repositories.h"

class PlayerRegistrationService : public PlayerService {
private:
protected:
    PlayerRepository playerRepository;
public:
    PlayerRegistrationService(Player& player);
    virtual ~PlayerRegistrationService();

    bool beginRegistration();
    bool endRegistration(const string& password, PersonSex::Sex sex);
};

