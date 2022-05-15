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

bool PlayerAuthorizationService::beginAuthorization() {

    // show authorization dialog
    Dialog* dialog = new AuthorizationDialog(player);
    return player.getDialog()->showDialog(dialog);
}

bool PlayerAuthorizationService::endAuthorization() {
    bool result;

    // player data
    result = playerRepository.loadAccount();

    if (!result) {
        player.getService()->getAuthenticationService()->end(PlayerAuthenticationService::ERROR_UNKNOWN);
        return false;
    }

    // player position
    PlayerPositionRepository positionRepository(player);
    result = positionRepository.loadPosition();

    if (!result) {
        player.getService()->getAuthenticationService()->end(PlayerAuthenticationService::ERROR_UNKNOWN);
        return false;
    }

    // set authorization status
    player.setAuthorized(true);

    // setup spawn info
    PersonSpawn* spawn = player.getSpawn();
    spawn->getSkin().setSkin(player.getSkin()->getSkin());
    spawn->getTeam().setTeam(PersonTeam::TEAM_NO);
    spawn->setSpawn(); // confirm changes

    player.getService()->getAuthenticationService()->endPlayerAuthorization();

    return true;
}