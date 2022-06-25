//
// Created by dubininvyu on 24.06.2022.
//

#include "PlayerRegistrationStateMachine.h"
#include "services.h"

/*
 * constructors & destructors
 */
PlayerRegistrationStateMachine_::PlayerRegistrationStateMachine_(Player* player) : player(player) {

}

PlayerRegistrationStateMachine_::~PlayerRegistrationStateMachine_() {

}

/*
 * methods
 * transition actions
 */
void PlayerRegistrationStateMachine_::enter_locale(Next const& event) {
    PlayerRegistrationService registrationService(player);
    bool result = registrationService.startLocaleEntering();

    if (!result) {
        PlayerRegistrationStateMachine* stateMachine = player->getStateMachineManager()->getPlayerRegistration();
        stateMachine->process_event(Error(Error::ERROR_REGISTRATION_LOCALE_SELECTION));

        return;
    }
}

void PlayerRegistrationStateMachine_::enter_password(Next const& event) {
    PlayerRegistrationService registrationService(player);
    bool result = registrationService.startPasswordEntering();

    if (!result) {
        PlayerRegistrationStateMachine* stateMachine = player->getStateMachineManager()->getPlayerRegistration();
        stateMachine->process_event(Error(Error::ERROR_REGISTRATION_PASSWORD_ENTERING));

        return;
    }
}

void PlayerRegistrationStateMachine_::enter_sex(Next const& event) {
    PlayerRegistrationService registrationService(player);
    bool result = registrationService.startSexEntering();

    if (!result) {
        PlayerRegistrationStateMachine* stateMachine = player->getStateMachineManager()->getPlayerRegistration();
        stateMachine->process_event(Error(Error::ERROR_REGISTRATION_SEX_ENTERING));

        return;
    }
}

void PlayerRegistrationStateMachine_::enter_age(Next const& event) {
    PlayerRegistrationService registrationService(player);
    bool result = registrationService.startAgeEntering();

    if (!result) {
        PlayerRegistrationStateMachine* stateMachine = player->getStateMachineManager()->getPlayerRegistration();
        stateMachine->process_event(Error(Error::ERROR_REGISTRATION_AGE_ENTERING));

        return;
    }
}

void PlayerRegistrationStateMachine_::register_account(Next const& event) {
    PlayerRegistrationService registrationService(player);
    bool result = registrationService.registerAccount();

    if (!result) {
        PlayerRegistrationStateMachine* stateMachine = player->getStateMachineManager()->getPlayerRegistration();
        stateMachine->process_event(Error(Error::ERROR_REGISTRATION_ACCOUNT_CREATING));

        return;
    }

    PlayerAuthorizationStateMachine* authorizationStateMachine = player->getStateMachineManager()->getPlayerAuthorization();
    authorizationStateMachine->start();
    authorizationStateMachine->process_event(Next());
}

void PlayerRegistrationStateMachine_::make_error(Error const& event) {
    PlayerRegistrationService registrationService(player);
    registrationService.stop(event.errorType);
}