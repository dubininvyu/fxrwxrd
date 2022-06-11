//
// Created by dubininvyu on 30.05.2022.
//

#include "StateMachineManager.h"

namespace pasm = player_authentication_sm;

StateMachineManager::StateMachineManager(Player* player) {
    authenticationStateMachine = new pasm::PlayerAuthenticationStateMachine(player);
}

StateMachineManager::~StateMachineManager() {
    delete authenticationStateMachine;
}

pasm::PlayerAuthenticationStateMachine* StateMachineManager::getPlayerAuthentication() {
    return authenticationStateMachine;
}