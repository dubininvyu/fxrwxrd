//
// Created by dubininvyu on 24.06.2022.
//

#include "PlayerAuthorizationStateMachine.h"

#include "dialogs.h"
#include "services.h"
#include "machines_events.h"

typedef Error::ErrorType ErrorType;

/*
 * constructors & destructors
 */
PlayerAuthorizationStateMachine_::PlayerAuthorizationStateMachine_(Player* player) : player(player) {

}

PlayerAuthorizationStateMachine_::~PlayerAuthorizationStateMachine_() {

}

/*
 * methods
 * transition actions
 */
void PlayerAuthorizationStateMachine_::locale_enter(Next const& event) {

    // get locale data
    PlayerAuthorizationService authorizationService(player);
    bool result = authorizationService.beginLocale();

    if (!result) {
        PlayerAuthorizationStateMachine* stateMachine = player->getStateMachineManager()->getPlayerAuthorization();
        stateMachine->process_event(Error(Error::ERROR_AUTHORIZATION_LOCALE_LOADING));
        return;
    }

    player->getStateMachineManager()->getPlayerAuthorization()->process_event(Next());
}

void PlayerAuthorizationStateMachine_::password_enter(Next const& event) {

    // show authorization dialog
    PlayerAuthorizationService authorizationService(player);
    bool result = authorizationService.beginPassword();

    if (!result) {
        PlayerAuthorizationStateMachine* stateMachine = player->getStateMachineManager()->getPlayerAuthorization();
        stateMachine->process_event(Error(Error::ERROR_AUTHORIZATION_PASSWORD_ENTERING));
        return;
    }
}

void PlayerAuthorizationStateMachine_::authorize(Next const& event) {
    PlayerAuthorizationService authorizationService(player);
    bool result = authorizationService.authorize();

    if (!result) {
        PlayerAuthorizationStateMachine* stateMachine = player->getStateMachineManager()->getPlayerAuthorization();
        stateMachine->process_event(Error(Error::ERROR_AUTHORIZATION_ACCOUNT_LOADING));
        return;
    }
}

void PlayerAuthorizationStateMachine_::make_error(Error const& event) {
    PlayerAuthorizationService authorizationService(player);
    authorizationService.stop(event.errorType);
}