//
// Created by dubininvyu on 03.05.2022.
//

#include "PlayerConnectHandler.h"
#include "Server.h"

#include "services.h"
#include "machines.h"

PlayerConnectHandler::PlayerConnectHandler(Player* player) : PlayerEventHandler(player) {

}

PlayerConnectHandler::~PlayerConnectHandler() {

}

bool PlayerConnectHandler::execute() {
    // init player data
    player->init();

    bool enabled = Server::getInstance().isEnabled();
    if (!enabled) {
        const string text = player->getAccount()->getLocale()->getText(TEXT_NOTIFICATION_SERVER_INACTIVE);
        player->sendMessage(text);
        return false;
    }

    // authenticate player
    PlayerAuthenticationService authenticationService(player);
    bool isRegistered = authenticationService.isRegistered();

    if (isRegistered) {
        PlayerAuthorizationStateMachine* stateMachine = player->getStateMachineManager()->getPlayerAuthorization();
        stateMachine->start();
        stateMachine->process_event(Next());
    }
    else {
        PlayerRegistrationStateMachine* stateMachine = player->getStateMachineManager()->getPlayerRegistration();
        stateMachine->start();
        stateMachine->process_event(Next());
    }

    return true;
}