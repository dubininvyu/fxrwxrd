//
// Created by dubininvyu on 07.05.2022.
//

#include "PlayerRegistrationService.h"

#include "dialogs.h"
#include "repositories.h"

PlayerRegistrationService::PlayerRegistrationService(Player& player) :
    PlayerService(player), playerRepository(player, Repository::MODE_NOPE) {

}

PlayerRegistrationService::~PlayerRegistrationService() {

}

bool PlayerRegistrationService::beginRegistration() {

    // show registration dialog
    Dialog* dialog = new RegistrationDialog(player);
    return player.getDialog()->showDialog(dialog);
}

bool PlayerRegistrationService::endRegistration(const string& password, PersonSex::Sex sex) {

    // player data
    unsigned int accountID = playerRepository.createAccount(password, sex);

    if (!accountID) {
        player.getService()->getAuthenticationService()->end(PlayerAuthenticationService::ERROR_UNKNOWN);
        return false;
    }

    player.setUID(accountID);

    // position
    PlayerPositionRepository positionRepository(player);
    unsigned int insertedID = positionRepository.createPosition();

    if (!insertedID) {
        player.getService()->getAuthenticationService()->end(PlayerAuthenticationService::ERROR_UNKNOWN);
        return false;
    }

    // others

    return true;
}