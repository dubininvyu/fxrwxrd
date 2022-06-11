//
// Created by dubininvyu on 07.05.2022.
//

#include "PlayerRegistrationService.h"

#include "dialogs.h"
#include "repositories.h"

PlayerRegistrationService::PlayerRegistrationService(Player* player) :
    PlayerService(player), playerRepository(player, Repository::MODE_NOPE) {

}

PlayerRegistrationService::~PlayerRegistrationService() {

}

bool PlayerRegistrationService::beginPasswordRegistration() {

    // show registration dialog
    Dialog* dialog = new RegistrationDialog(player, RegistrationDialog::PAGE_PASSWORD);
    return player->getDialogManager()->showDialog(dialog);
}

bool PlayerRegistrationService::beginSexRegistration() {

    // show registration dialog
    Dialog* dialog = new RegistrationDialog(player, RegistrationDialog::PAGE_SEX);
    return player->getDialogManager()->showDialog(dialog);
}

bool PlayerRegistrationService::endRegistration() {

    string password = player->getPassword()->getPassword();
    PersonSex::Sex sex = player->getSex()->getSex();

    // player data
    unsigned int accountID = playerRepository.createAccount(password, sex);

    if (!accountID) {
        return false;
    }

    player->setUID(accountID);

    // position
    PlayerPositionRepository positionRepository(player);
    unsigned int insertedID = positionRepository.createPosition();

    if (!insertedID) {
        return false;
    }

    // others

    return true;
}