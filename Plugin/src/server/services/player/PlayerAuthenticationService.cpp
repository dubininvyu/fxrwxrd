//
// Created by dubininvyu on 07.05.2022.
//

#include "PlayerAuthenticationService.h"

#include "dialogs.h"
#include "PlayerRepository.h"

#include "services.h"

PlayerAuthenticationService::PlayerAuthenticationService(Player& player) :
    PlayerService(player), playerRepository(player, Repository::MODE_NOPE) {
}

PlayerAuthenticationService::~PlayerAuthenticationService() {

}

bool PlayerAuthenticationService::startAuthentication() {

    // fix arrows and 'Spawn' button
    player.getCamera()->setSpectatingMode(PersonCamera::MODE_ON);

    // authentication
    unsigned int accountID = playerRepository.getAccountID();

    if (!accountID) { // registration
        PlayerRegistrationService registrationService(player);
        registrationService.startRegistration();
        return true;
    }

    // authorization
    player.setUID(accountID);

    Language language = playerRepository.getLanguage();
    player.setLocale(language);

    PlayerAuthorizationService authorizationService(player);
    authorizationService.startAuthorization();

    return true;
}

bool PlayerAuthenticationService::finishAuthentication() {
    // fix arrows and 'Spawn' button
    player.getCamera()->setSpectatingMode(PersonCamera::MODE_OFF);

    // create player session
    PlayerSessionService sessionService(player);
    sessionService.createConnectSession();

    return true;
}