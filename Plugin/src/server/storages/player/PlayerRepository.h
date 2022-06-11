//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "PersonSex.h"
#include "MySQLRepository.h"
#include "PlayerDisconnectHandler.h"
#include "languages.h"

class Player;

class PlayerRepository : public MySQLRepository {
private:
protected:
    Player* player;
    Mode mode;
public:
    PlayerRepository(Player* player, const Mode mode = MODE_NOPE);
    virtual ~PlayerRepository();

    virtual bool preload();

    bool isRegistered() const;
    bool isRegisteredByPassword(const string& password) const;

    bool loadAccount();
    unsigned int createAccount(const string& password, PersonSex::Sex sex);

    unsigned int getUID() const;
    unsigned int getUIDByPassword(const string& password) const;

    Language getLanguage() const;
};