//
// Created by dubininvyu on 07.05.2022.
//

#include "PlayerAuthenticationService.h"

#include "Player.h"

#include "dialogs.h"
#include "services.h"
#include "repositories.h"

PlayerAuthenticationService::PlayerAuthenticationService(Player& player) :
    PlayerService(player), playerRepository(player, Repository::MODE_NOPE) {
}

PlayerAuthenticationService::~PlayerAuthenticationService() {

}

void PlayerAuthenticationService::setStage(AuthenticationStage stage) {
    this->stage = stage;
}

void PlayerAuthenticationService::nextStage() {
    stage++;
}

void PlayerAuthenticationService::begin() {
    // fix arrows and 'Spawn' button
    player.getCamera()->setSpectatingMode(PersonCamera::MODE_ON);

    // begin
    this->stage = STAGE_PLAYER_AUTHENTICATION;
    execute();
}

void PlayerAuthenticationService::execute() {
    switch (stage) {
        case STAGE_PLAYER_AUTHENTICATION: {
            beginPlayerAuthentication();
            break;
        }
        case STAGE_ADMIN_AUTHENTICATION: {
            beginAdminAuthentication();
            break;
        }

        case STAGE_COUNT: {
            end(ERROR_NONE);
            break;
        }
    }
}

void PlayerAuthenticationService::beginPlayerAuthentication() {
    unsigned int accountID = playerRepository.getUID();
    player.setUID(accountID);

    Language language = playerRepository.getLanguage();
    player.setLocale(language);

    if (!accountID) {
        beginPlayerRegistration();
    }
    else {
        beginPlayerAuthorization();
    }
}

void PlayerAuthenticationService::beginPlayerAuthorization() {
    PlayerAuthorizationService authorizationService(player);
    authorizationService.beginAuthorization();
}

void PlayerAuthenticationService::endPlayerAuthorization() {
    endPlayerAuthentication();
}

void PlayerAuthenticationService::endPlayerAuthentication() {
    nextStage();
    execute();
}

void PlayerAuthenticationService::beginPlayerRegistration() {
    PlayerRegistrationService registrationService(player);
    registrationService.beginRegistration();
}

void PlayerAuthenticationService::endPlayerRegistration() {
    stage = STAGE_PLAYER_AUTHENTICATION;
    execute();
}

void PlayerAuthenticationService::beginAdminAuthentication() {
    AdminRepository adminRepository(player);
    unsigned int adminID = adminRepository.getUID();
    player.getAdmin()->setUID(adminID);

    if (!adminID) {
        // player is not admin, go to the next stage
        nextStage();
        return execute();
    }

    beginAdminAuthorization();
}

void PlayerAuthenticationService::beginAdminAuthorization() {
    AdminAuthorizationService authorizationService(player);
    authorizationService.beginAuthorization();
}

void PlayerAuthenticationService::endAdminAuthorization() {
    player.sendMessage("You are logged as administrator");
    endAdminAuthentication();
}

void PlayerAuthenticationService::endAdminAuthentication() {
    nextStage();
    execute();
}


void PlayerAuthenticationService::end(AuthenticationError error) {
    if (error == ERROR_NONE) {
        // fix arrows and 'Spawn' button
        player.getCamera()->setSpectatingMode(PersonCamera::MODE_OFF);

        // create player session
        PlayerSessionService sessionService(player);
        sessionService.createConnectSession();
    }

    if (error == ERROR_UNKNOWN) {
        player.sendMessage(player.getLocale()->getText(TEXT_ERROR));
    }
}