//
// Created by dubininvyu on 10.05.2022.
//

#include "ServiceManager.h"

ServiceManager::ServiceManager(Player* player) : player(player) {
    authenticationService = new PlayerAuthenticationService(*player);
}

ServiceManager::~ServiceManager() {
    delete authenticationService;
}

PlayerAuthenticationService* ServiceManager::getAuthenticationService() {
    return authenticationService;
}