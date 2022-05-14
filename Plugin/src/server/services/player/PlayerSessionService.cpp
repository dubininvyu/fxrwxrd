//
// Created by dubininvyu on 07.05.2022.
//

#include "PlayerSessionService.h"
#include "PlayerRepository.h"

PlayerSessionService::PlayerSessionService(Player& player) :
    PlayerService(player), sessionRepository(player) {
}

PlayerSessionService::~PlayerSessionService() {

}

void PlayerSessionService::createConnectSession() {
    sessionRepository.createSession(player.getUID(), player.getIP()->getIP());
}

void PlayerSessionService::createDisconnectSession(PlayerDisconnectHandler::Reason reason) {
    sessionRepository.updateSession(reason);
}