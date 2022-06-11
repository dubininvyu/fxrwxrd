//
// Created by dubininvyu on 30.05.2022.
//

#pragma once

#include "machines.h"

class Player;

namespace pasm = player_authentication_sm;

class StateMachineManager {
public:
private:
protected:
    Player* player;

    pasm::PlayerAuthenticationStateMachine* authenticationStateMachine;
public:
    StateMachineManager(Player* player);
    ~StateMachineManager();

    pasm::PlayerAuthenticationStateMachine* getPlayerAuthentication();
};

