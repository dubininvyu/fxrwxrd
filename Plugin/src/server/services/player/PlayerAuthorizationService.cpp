//
// Created by dubininvyu on 07.05.2022.
//

#include "PlayerAuthorizationService.h"

#include "dialogs.h"
#include "services.h"
#include "repositories.h"

PlayerAuthorizationService::PlayerAuthorizationService(Player* player) :
    PlayerService(player), playerRepository(player, Repository::MODE_NOPE) {
}

PlayerAuthorizationService::~PlayerAuthorizationService() {

}

bool PlayerAuthorizationService::beginPasswordAuthorization() {

    // show authorization dialog
    Dialog* dialog = new AuthorizationDialog(player, AuthorizationDialog::PAGE_PASSWORD);
    return player->getDialogManager()->showDialog(dialog);
}

bool PlayerAuthorizationService::endAuthorization() {
    bool result;

    // player data
    result = playerRepository.load();

    if (!result) {
        return false;
    }

    // setup spawn info
    PersonSpawn* spawn = player->getSpawn();
    spawn->getSkin().setSkin(player->getSkin()->getSkin());
    spawn->getTeam().setTeam(PersonTeam::TEAM_NO);
    spawn->setSpawnInfo(); // confirm changes

    return true;
}