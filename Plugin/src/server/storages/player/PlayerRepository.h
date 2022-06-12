//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "PersonSex.h"
#include "MySQLRepository.h"
#include "RepositoryInterface.h"
#include "PlayerDisconnectHandler.h"
#include "languages.h"

class Player;

class PlayerRepository : public MySQLRepository, virtual public RepositoryInterface {
private:
protected:
    Player* player;
    Mode mode;
public:
    PlayerRepository(Player* player, const Mode mode = MODE_NOPE);
    virtual ~PlayerRepository();

    virtual bool preload();

    virtual unsigned int load();
    virtual unsigned int block();
    virtual unsigned int update();
    virtual unsigned int create();

    bool isRegistered() const;
    bool isRegisteredByPassword(const string& password) const;

    unsigned int getUID() const;
    unsigned int getUIDByPassword(const string& password) const;

    Language getLanguage() const;
};