//
// Created by dubininvyu on 03.05.2022.
//

#include "PlayerSpawnHandler.h"

#include "Player.h"
#include "natives.h"

PlayerSpawnHandler::PlayerSpawnHandler(Player* player) :
        PlayerEventHandler(player) {

}

PlayerSpawnHandler::~PlayerSpawnHandler() {

}

bool PlayerSpawnHandler::execute() {

    if (!player->isAuthorized()) {
        api_server::native::Kick(player->getID());
        return false;
    }

    /* setup player position */
    auto world = player->getSpawn()->getPosition().getWorld();
    player->getPosition()->setWorld(world);

    auto interior = player->getSpawn()->getPosition().getInterior();
    player->getPosition()->setInterior(interior);

    /* setup player variables */
    player->setSpawned(true);

    return true;
}