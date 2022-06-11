//
// Created by dubininvyu on 03.05.2022.
//

#include "PlayerDisconnectHandler.h"

#include "services.h"
#include "repositories.h"

PlayerDisconnectHandler::PlayerDisconnectHandler(Player* player, Reason reason) :
        PlayerEventHandler(player), reason(reason) {

}

PlayerDisconnectHandler::~PlayerDisconnectHandler() {

}

bool PlayerDisconnectHandler::execute() {

    /* save player position */
    PlayerPositionService positionService(player);
    positionService.savePosition();

    /* player session */
    PlayerSessionService sessionService(player);
    sessionService.createDisconnectSession(reason);

    return true;
}