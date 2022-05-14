//
// Created by dubininvyu on 07.05.2022.
//

#include "PlayerAuthorizationService.h"

#include "dialogs.h"
#include "services.h"
#include "repositories.h"

PlayerAuthorizationService::PlayerAuthorizationService(Player& player) :
    PlayerService(player), playerRepository(player, Repository::MODE_NOPE) {
}

PlayerAuthorizationService::~PlayerAuthorizationService() {

}

bool PlayerAuthorizationService::startAuthorization() {

    // show authorization dialog
    Dialog* dialog = new AuthorizationDialog(player);
    return player.getDialog()->showDialog(dialog);
}

bool PlayerAuthorizationService::finishAuthorization() {
    bool result = true;

    // player data
    result &= playerRepository.loadAccount();

    // player position
    PlayerPositionRepository positionRepository(player);
    result &= positionRepository.loadPosition();

    // set authorization status
    player.setAuthorized(true);

    // setup spawn info
    PersonSpawn* spawn = player.getSpawn();
    spawn->getSkin().setSkin(player.getSkin()->getSkin());
    spawn->getTeam().setTeam(PersonTeam::TEAM_NO);
    spawn->setSpawn(); // confirm changes

    PlayerAuthenticationService authenticationService(player);
    authenticationService.finishAuthentication();

    return result;
}