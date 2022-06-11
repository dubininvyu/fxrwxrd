//
// Created by dubininvyu on 30.05.2022.
//

#include "PlayerAuthenticationStateMachine.h"

#include "Player.h"
#include "services.h"

using namespace player_authentication_sm;

/* state machine */
PlayerAuthenticationStateMachine_::PlayerAuthenticationStateMachine_(Player* player) : player(player) {

}

/* transition actions */
void PlayerAuthenticationStateMachine_::authorization_password(Start const& event) {
    PlayerAuthorizationService authorizationService(player);
    authorizationService.beginPasswordAuthorization();
}

void PlayerAuthenticationStateMachine_::authorization_end(Next const& event) {
    PlayerAuthorizationService authorizationService(player);
    bool result = authorizationService.endAuthorization();

    if(result) {
        player->setAuthorized(true);
        player->getSpawn()->spawn(); // spawn player

        PlayerSessionService sessionService(player);
        sessionService.createConnectSession();
    }
    else {
        player->sendMessage(player->getLocale()->getText(TEXT_ERROR));
    }
}

void PlayerAuthenticationStateMachine_::registration_password(Start const& event) {
    PlayerRegistrationService registrationService(player);
    registrationService.beginPasswordRegistration();
}

void PlayerAuthenticationStateMachine_::registration_sex(Next const& event) {
    PlayerRegistrationService registrationService(player);
    registrationService.beginSexRegistration();
}

void PlayerAuthenticationStateMachine_::registration_end(Next const& event) {
    PlayerRegistrationService registrationService(player);
    bool result = registrationService.endRegistration();

    if (result) {
        player->getStateMachineManager()->getPlayerAuthentication()->process_event(player_authentication_sm::Start());
    }
    else {
        player->sendMessage(player->getLocale()->getText(TEXT_ERROR));
    }
}

/* guard conditions */
bool PlayerAuthenticationStateMachine_::isRegistered(Start const& event) {
    PlayerAuthenticationService authenticationService(player);
    return authenticationService.isRegistered();
}

bool PlayerAuthenticationStateMachine_::isNotRegistered(Start const& event) {
    return !isRegistered(event);
}