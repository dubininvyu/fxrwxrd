//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "Person.h"
#include "MySQLRepository.h"
#include "PlayerDisconnectHandler.h"
#include "Account.h"

#include "languages.h"

class Player;

typedef PersonSex::Sex Sex;
typedef PersonAge::Age Age;

class PlayerRepository : public MySQLRepository {
private:
protected:
    Player* player;
    Mode mode;
public:
    /*
     * constructors & destructors
     */
    PlayerRepository(Player* player, const Mode mode = MODE_NOPE);
    virtual ~PlayerRepository();

    /*
     * methods
     * virtual
     */
    virtual bool preload();

    virtual unsigned int load();
    virtual unsigned int block();
    virtual unsigned int update();
    virtual accountID_t create(const string& name, const string& password, const Sex sex, const Age age);

    /*
     * methods
     * for checking registration
     */;
    accountID_t getID() const;
    accountID_t getIDByPassword(const string& password) const;

    Language getLocale() const;

    /*
     * methods
     * ...
     */

};