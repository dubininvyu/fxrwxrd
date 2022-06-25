//
// Created by dubininvyu on 15.05.2022.
//

#include "AccountPassword.h"
#include "Account.h"

using namespace std;

AccountPassword::AccountPassword(Account* player, const string& password) : account(account), password(password) {

}

bool AccountPassword::setPassword(const string& password, const bool reWrite) {
    if (!isValid(password)) {
        return false;
    }

    this->password = password;

    if (reWrite) {

    }

    return true;
}

string AccountPassword::getPassword() const {
    return this->password;
}

bool AccountPassword::isValid() {
    return isValid(this->password);
}

bool AccountPassword::isValid(const string& password) {
    return (password.length() >= MIN_LENGTH && password.length() <= MAX_LENGTH);
}