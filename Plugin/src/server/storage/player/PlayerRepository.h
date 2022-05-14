//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "MySQLRepository.h"
#include "Player.h"
#include "PlayerDisconnectHandler.h"
#include "languages.h"

class PlayerRepository : public MySQLRepository {
private:
protected:
    Player& player;
    Mode mode;
public:
    PlayerRepository(Player& player, const Mode mode);
    virtual ~PlayerRepository();

    virtual bool preload();

    bool isRegistered();

    bool loadAccount();
    unsigned int createAccount(const string& password, Person::Sex sex);

    unsigned int getAccountID() const;
    unsigned int getAccountID(const string& password) const;

    Language getLanguage() const;
};