//
// Created by dubininvyu on 03.05.2022.
//

#include "PlayerRequestClassHandler.h"

#include "natives.h"
#include "PlayerAuthenticationService.h"

PlayerRequestClassHandler::PlayerRequestClassHandler(Player& player, unsigned int classID) :
        PlayerEventHandler(player), classID(classID) {

}

PlayerRequestClassHandler::~PlayerRequestClassHandler() {

}

bool PlayerRequestClassHandler::execute() {
    player.setSpawned(false);

    if (player.isAuthorized()) { // player has clicked F4 and had died
        player.getSpawn()->setSpawn();
        return player.getSpawn()->spawn();
    }

    return true;
}