//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "PlayerAuthenticationService.h"

using namespace std;

class Player;

class ServiceManager {
public:
private:
protected:
    Player* player;

    PlayerAuthenticationService* authenticationService;
public:
    ServiceManager(Player* player);
    ~ServiceManager();

    PlayerAuthenticationService* getAuthenticationService();
};