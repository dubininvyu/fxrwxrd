//
// Created by dubininvyu on 07.05.2022.
//

#include "PlayerRegistrationService.h"

#include "logs.h"
#include "dialogs.h"
#include "repositories.h"

typedef PersonSex::Sex Sex;
typedef PersonAge::Age Age;

PlayerRegistrationService::PlayerRegistrationService(Player* player) :
    PlayerService(player), playerRepository(player, Repository::MODE_NOPE) {

}

PlayerRegistrationService::~PlayerRegistrationService() {

}

bool PlayerRegistrationService::startLocaleEntering() {

    // show locale select dialog
    Dialog* dialog = new RegistrationDialog(player, RegistrationDialog::PAGE_LOCALE);
    return player->getDialogManager()->showDialog(dialog);
}

bool PlayerRegistrationService::startPasswordEntering() {

    // show registration dialog
    Dialog* dialog = new RegistrationDialog(player, RegistrationDialog::PAGE_PASSWORD);
    return player->getDialogManager()->showDialog(dialog);
}

bool PlayerRegistrationService::startSexEntering() {

    // show registration dialog
    Dialog* dialog = new RegistrationDialog(player, RegistrationDialog::PAGE_SEX);
    return player->getDialogManager()->showDialog(dialog);
}

bool PlayerRegistrationService::startAgeEntering() {

    // show age entering dialog
    Dialog* dialog = new RegistrationDialog(player, RegistrationDialog::PAGE_AGE);
    return player->getDialogManager()->showDialog(dialog);
}

bool PlayerRegistrationService::registerAccount() {

    // player data
    const string playerName = player->getName()->getName();
    const string playerPassword = player->getAccount()->getPassword()->getPassword();
    const Sex sex = player->getSex()->getSex();
    const Age age = player->getAge()->getAge();

    accountID_t accountID = playerRepository.create(playerName, playerPassword, sex, age);

    if (!Account::isValid(accountID)) {
        return false;
    }

    player->getAccount()->setID(accountID);

    // position
    PlayerPositionRepository positionRepository(player);
    size_t insertedID = positionRepository.create();

    if (!insertedID) {
        return false;
    }

    // others

    return true;
}

bool PlayerRegistrationService::stop(const ErrorType error) {
    // notify player about the error
    player->sendMessage(player->getAccount()->getLocale()->getText(TEXT_ERROR));

    // save data about the error into server logs
    WarningLog(__FILE__, __LINE__, "Error account registration #" + to_string(error)).print();

    return true;
}