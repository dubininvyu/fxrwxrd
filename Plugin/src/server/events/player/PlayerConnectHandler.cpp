//
// Created by dubininvyu on 03.05.2022.
//

#include "PlayerConnectHandler.h"

#include "services.h"
#include "managers.h"

PlayerConnectHandler::PlayerConnectHandler(Player& player) :
        PlayerEventHandler(player) {

}

PlayerConnectHandler::~PlayerConnectHandler() {

}

bool PlayerConnectHandler::execute() {
    // init player data
    player.init();

    // authentication system
    player.getService()->getAuthenticationService()->begin();

    return true;
}