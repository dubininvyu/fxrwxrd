//
// Created by dubininvyu on 07.05.2022.
//

#include "Player.h"
#include "services.h"

/*
 * constructors & destructors
 */
PlayerAuthenticationService::PlayerAuthenticationService(Player* player) :
    PlayerService(player), playerRepository(player, Repository::MODE_NOPE) {
}

PlayerAuthenticationService::~PlayerAuthenticationService() {

}

/*
 * methods
 * for checking registration
 */
bool PlayerAuthenticationService::isRegistered() {
    accountID_t accountID = playerRepository.getID();
    player->getAccount()->setID(accountID);

    return Account::isValid(accountID);
}

bool PlayerAuthenticationService::isRegisteredByPassword(const string& password) const {
    accountID_t accountID = playerRepository.getIDByPassword(password);
    return Account::isValid(accountID);
}

/*
 * methods
 * for initialization
 */
void PlayerAuthenticationService::initLocale() {
    Language language = playerRepository.getLocale();
    player->getAccount()->setLocale(language);
}