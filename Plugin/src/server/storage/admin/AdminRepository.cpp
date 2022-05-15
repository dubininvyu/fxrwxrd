//
// Created by dubininvyu on 10.05.2022.
//

#include "AdminRepository.h"

#include "Player.h"
#include "Exception.h"
#include "MainDatabase.h"

#include "boost/format.hpp"

using namespace std;
using namespace boost;

AdminRepository::AdminRepository(Player& player, const Mode mode) : MySQLRepository(), player(player), mode(mode) {
    if (mode & MODE_READ_ALL) {
        preload();
    }
}

AdminRepository::~AdminRepository() {

}

bool AdminRepository::preload() {
    return true;
}

bool AdminRepository::isRegistered() const {
    return (getUID() > 0);
}

bool AdminRepository::loadAdmin() {
    format fmt = format("SELECT * FROM `admins` WHERE `player_id` = '%d' LIMIT 1")
                 % player.getUID();

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    SQLResult result = connector.storeResult();
    if (!result) {
        return false;
    }

    if (!result.getNumRows()) {
        return false;
    }

    enum {
        ID, PLAYER_ID, LEVEL, NAME, PASSWORD, GET_DATE
    };

    MYSQL_ROW row = result.fetchRow();

    unsigned int uid = atoi(row[ID]);
    player.getAdmin()->setUID(uid);

    Admin::AdminLevel level = Admin::AdminLevel(atoi(row[LEVEL]));
    player.getAdmin()->setLevel(level);

    string name = row[NAME];
    player.getAdmin()->setName(name);
}

unsigned int AdminRepository::createAdmin(const Admin::AdminLevel level, const string& password) {
    format fmt = format("INSERT INTO `admins` (`id`, `level`, `password`) VALUES ('%d', '%d', MD5('%s'))")
                 % player.getAdmin()->getUID() % level % password;

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    return connector.getInsertedID();
}

bool AdminRepository::destroyAdmin() {
    format fmt = format("DELETE FROM `admins` WHERE `id` = '%d' LIMIT 1")
                 % player.getAdmin()->getUID();

    MySQLConnector connector(MainDatabase::getInstance());
    bool result = connector.query(fmt.str());

    return !result;
}

unsigned int AdminRepository::getUID() const {
    format fmt = format(
            "SELECT `id` FROM `admins` WHERE `player_id` = '%d' LIMIT 1")
            % player.getUID();

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    SQLResult result = connector.storeResult();
    if (!result) {
        return 0;
    }

    if (!result.getNumRows()) {
        return 0;
    }

    enum {ID};

    MYSQL_ROW row = result.fetchRow();
    return atoi(row[ID]);
}

unsigned int AdminRepository::getUID(const string& password) const {
    format fmt = format("SELECT `id` FROM `admins` WHERE `player_id` = '%d' AND `password` = MD5('%s') LIMIT 1")
                 % player.getUID() % password;

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    SQLResult result = connector.storeResult();
    if (!result) {
        return 0;
    }

    if (!result.getNumRows()) {
        return 0;
    }

    enum {ID};

    MYSQL_ROW row = result.fetchRow();
    return atoi(row[ID]);
}