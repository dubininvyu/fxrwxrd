//
// Created by dubininvyu on 15.05.2022.
//

#include "AdminPassword.h"

#include "Player.h"

using namespace std;

AdminPassword::AdminPassword(const string& password) : password(password) {

}

void AdminPassword::setPassword(const string& password) {
    this->password = password;
}

string AdminPassword::getPassword() const {
    return this->password;
}

bool AdminPassword::isValid() {
    return isValid(this->password);
}

bool AdminPassword::isValid(const string& password) {
    return (password.length() >= MIN_LENGTH && password.length() <= MAX_LENGTH);
}