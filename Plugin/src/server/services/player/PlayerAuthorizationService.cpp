//
// Created by dubininvyu on 07.05.2022.
//

#include "PlayerAuthorizationService.h"

#include "logs.h"
#include "dialogs.h"
#include "services.h"
#include "repositories.h"
#include "machines_events.h"

/*
 * constructors & destructors
 */

PlayerAuthorizationService::PlayerAuthorizationService(Player* player) :
    PlayerService(player), playerRepository(player, Repository::MODE_NOPE) {
}

PlayerAuthorizationService::~PlayerAuthorizationService() {

}

/*
 * methods
 */
bool PlayerAuthorizationService::beginLocale() {
    PlayerAuthenticationService authenticationService(player);
    authenticationService.initLocale();

    return true;
}

bool PlayerAuthorizationService::beginPassword() {

    // show authorization dialog
    Dialog* dialog = new AuthorizationDialog(player, AuthorizationDialog::PAGE_PASSWORD);
    return player->getDialogManager()->showDialog(dialog);
}

bool PlayerAuthorizationService::authorize() {
    bool result;

    // player data
    result = playerRepository.load();

    if (!result) {
        return false;
    }

    PlayerSessionService sessionService(player);
    sessionService.createConnectSession();

    // setup spawn info
    PersonSpawn* spawn = player->getSpawn();
    spawn->getSkin().setSkin(player->getSkin()->getSkin());
    spawn->getTeam().setTeam(PersonTeam::TEAM_NO);
    spawn->setSpawnInfo(); // confirm changes

    // spawn player
    player->setAuthorized(true);
    spawn->spawn();

    return true;
}

bool PlayerAuthorizationService::stop(const ErrorType error) { // if it's an error
    // notify player about the error
    player->sendMessage(player->getAccount()->getLocale()->getText(TEXT_ERROR));

    // save data about the error into server logs
    WarningLog(__FILE__, __LINE__, "Error account authorization #" + to_string(error)).print();
    return true;
}