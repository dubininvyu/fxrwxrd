//
// Created by dubininvyu on 01.05.2022.
//

#include "Admin.h"

vector<Player*> Admin::admins = {};

Admin::Admin(Player* player) : player(player), level(LEVEL_NONE), authorized(false) {
    password = new AdminPassword();
}

Admin::~Admin() {
    delete password;
}

void Admin::setID(const adminID_t id) {
    this->id = id;
}

adminID_t Admin::getID() const {
    return this->id;
}

bool Admin::isAdmin() const {
    return (level > LEVEL_NONE);
}

void Admin::giveAdmin() {
    admins.push_back(player);
}

void Admin::takeAdmin() {
    for (auto i = admins.begin(); i != admins.end(); i++) {
        if (*i != player) {
            continue;
        }

        admins.erase(i);
        break;
    }
}

void Admin::setLevel(AdminLevel level) {
    if (this->level == LEVEL_NONE && level > LEVEL_NONE) {
        giveAdmin();
    }
    else if (this->level > LEVEL_NONE && level == LEVEL_NONE) {
        takeAdmin();
    }

    this->level = level;
}

Admin::AdminLevel Admin::getLevel() const {
    return this->level;
}

void Admin::setName(const string& name) {
    this->name = name;
}

string Admin::getName() const {
    return this->name;
}

void Admin::setAuthorized(const bool isAuthorized) {
    this->authorized = isAuthorized;
}

bool Admin::isAuthorized() const {
    return this->authorized;
}