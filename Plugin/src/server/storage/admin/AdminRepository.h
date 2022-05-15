//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "MySQLRepository.h"
#include "Player.h"

class AdminRepository : public MySQLRepository {
private:
protected:
    Player& player;
    Mode mode;
public:
    AdminRepository(Player& player, const Mode mode = MODE_NOPE);
    virtual ~AdminRepository();

    virtual bool preload();

    bool isRegistered() const;

    bool loadAdmin();
    unsigned int createAdmin(const Admin::AdminLevel level, const string& password);
    bool destroyAdmin();

    unsigned int getUID() const;
    unsigned int getUID(const string& password) const;
};