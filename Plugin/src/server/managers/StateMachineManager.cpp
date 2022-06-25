//
// Created by dubininvyu on 30.05.2022.
//

#include "StateMachineManager.h"

#include "machines.h"

StateMachineManager::StateMachineManager(Player* player) : player(player) {

    authorizationStateMachine = new PlayerAuthorizationStateMachine(player);
    registrationStateMachine = new PlayerRegistrationStateMachine(player);
}

StateMachineManager::~StateMachineManager() {
    delete authorizationStateMachine;
    delete registrationStateMachine;
}

PlayerAuthorizationStateMachine* StateMachineManager::getPlayerAuthorization() {
    return authorizationStateMachine;
}

PlayerRegistrationStateMachine* StateMachineManager::getPlayerRegistration() {
    return registrationStateMachine;
}