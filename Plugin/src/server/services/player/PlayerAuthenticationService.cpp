//
// Created by dubininvyu on 07.05.2022.
//

#include "Player.h"
#include "services.h"

PlayerAuthenticationService::PlayerAuthenticationService(Player* player) :
    PlayerService(player), playerRepository(player, Repository::MODE_NOPE) {
}

PlayerAuthenticationService::~PlayerAuthenticationService() {

}

bool PlayerAuthenticationService::isRegistered() const {
    return playerRepository.isRegistered();
}

unsigned int PlayerAuthenticationService::getUIDByPassword(const string& password) const {
    return playerRepository.getUIDByPassword(password);
}