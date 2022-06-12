//
// Created by dubininvyu on 07.05.2022.
//

#include "PlayerSessionService.h"
#include "PlayerRepository.h"

PlayerSessionService::PlayerSessionService(Player* player) :
    PlayerService(player), sessionRepository(player) {
}

PlayerSessionService::~PlayerSessionService() {

}

void PlayerSessionService::createConnectSession() {
    sessionRepository.create();
}

void PlayerSessionService::createDisconnectSession(PlayerDisconnectHandler::Reason reason) {
    sessionRepository.update(reason);
}