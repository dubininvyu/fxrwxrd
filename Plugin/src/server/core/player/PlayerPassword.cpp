//
// Created by dubininvyu on 15.05.2022.
//

#include "PlayerPassword.h"

#include "Player.h"

using namespace std;

PlayerPassword::PlayerPassword(Player* player, const string& password) : player(player), password(password) {

}

bool PlayerPassword::setPassword(const string& password, const bool reWrite) {
    if (!isValid(password)) {
        return false;
    }

    this->password = password;

    if (reWrite) {
        // saving password into database
    }

    return true;
}

string PlayerPassword::getPassword() const {
    return this->password;
}

bool PlayerPassword::isValid() {
    return isValid(this->password);
}

bool PlayerPassword::isValid(const string& password) {
    return (password.length() >= MIN_LENGTH && password.length() <= MAX_LENGTH);
}