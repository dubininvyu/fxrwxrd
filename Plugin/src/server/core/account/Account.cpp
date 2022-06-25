//
// Created by dubininvyu on 17.06.2022.
//

#include "Account.h"
#include "Player.h"

#include "logs.h"

/*
 * constructors & destructors
 */
Account::Account(Player* player) : player(player) {
    locale = nullptr;
    level = new AccountLevel(this);
    license = new AccountLicense(this);
    password = new AccountPassword(this);
}

Account::~Account() {
    delete level;
    delete license;
    delete password;
}

/*
 * methods
 * static
 */
const bool Account::isValid(const accountID_t accountID) {
    return (accountID >= MIN_ID && accountID <= MAX_ID);
}

/*
 * methods
 * setters & getters
 */
void Account::setID(const accountID_t id) {
    this->id = id;
}

accountID_t Account::getID() const {
    return id;
}

void Account::setLocale(const Language language) {
    this->locale = &AccountLocale::getLocale(language);
}

AccountLocale* Account::getLocale() {
    if (!locale) {
        return &AccountLocale::getLocale(LANGUAGE_DEFAULT);
    }

    return locale;
}

Player* Account::getPlayer() {
    return player;
}

AccountLevel* Account::getLevel() {
    return level;
}

AccountLicense* Account::getLicense() {
    return license;
}

AccountPassword* Account::getPassword() {
    return password;
}