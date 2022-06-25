//
// Created by dubininvyu on 30.05.2022.
//

#pragma once

#include "machines.h"

class Player;

class StateMachineManager {
public:
private:
protected:
    Player* player;

    PlayerAuthorizationStateMachine* authorizationStateMachine;
    PlayerRegistrationStateMachine* registrationStateMachine;
public:
    StateMachineManager(Player* player);
    ~StateMachineManager();

    PlayerAuthorizationStateMachine* getPlayerAuthorization();
    PlayerRegistrationStateMachine* getPlayerRegistration();
};

