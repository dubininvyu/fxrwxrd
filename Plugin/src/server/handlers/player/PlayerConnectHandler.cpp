//
// Created by dubininvyu on 03.05.2022.
//

#include "PlayerConnectHandler.h"

#include "services.h"
#include "managers.h"
#include "machines.h"

PlayerConnectHandler::PlayerConnectHandler(Player* player) :
        PlayerEventHandler(player) {

}

PlayerConnectHandler::~PlayerConnectHandler() {

}

bool PlayerConnectHandler::execute() {
    // init player data
    player->init();

    // authentication system
    player->getStateMachineManager()->getPlayerAuthentication()->start();
    player->getStateMachineManager()->getPlayerAuthentication()->process_event(player_authentication_sm::Start());

    return true;
}