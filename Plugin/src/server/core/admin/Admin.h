//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include <string>
#include <vector>

#include "AdminPassword.h"

class Player;

using namespace std;

typedef size_t adminID_t;

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

    adminID_t id;
    string name;

    static vector<Player*> admins;

    bool authorized;

    void giveAdmin();
    void takeAdmin();
public:
    Admin(Player* player);
    ~Admin();

    void setID(const adminID_t uid);
    adminID_t getID() const;

    bool isAdmin() const;

    void setLevel(AdminLevel level);
    AdminLevel getLevel() const;

    void setName(const string& name);
    string getName() const;

    void setAuthorized(const bool isAuthorized);
    bool isAuthorized() const;
};

