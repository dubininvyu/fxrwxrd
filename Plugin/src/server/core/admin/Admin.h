//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include <string>
#include <vector>

#include "AdminPassword.h"

class Player;

using namespace std;

class Admin {
public:
    enum AdminLevel {
        LEVEL_NONE = 0,
        LEVEL_SUPPORTER,
        LEVEL_SUPER_SUPPORTER,
        LEVEL_MODERATOR,
        LEVEL_SUPER_MODERATOR,
        LEVEL_ADMINISTRATOR,
        LEVEL_SUPER_ADMINISTRATOR
    };
private:
protected:
    Player* player;

    AdminLevel level;
    AdminPassword* password;

    string name;

    static vector<Player*> admins;

    void giveAdmin();
    void takeAdmin();
public:
    Admin(Player* player);
    ~Admin();

    bool isAdmin() const;

    void setLevel(AdminLevel level);
    AdminLevel getLevel() const;

    void setName(const string& name);
    string getName() const;
};

