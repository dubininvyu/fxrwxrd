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

AdminRepository::AdminRepository(Player* player, const Mode mode) : MySQLRepository(mode), player(player) {
    if (mode & MODE_READ) {
        preload();
    }
}

AdminRepository::~AdminRepository() {

}

bool AdminRepository::preload() {
    return true;
}

bool AdminRepository::isRegistered() const {
    return (getID() > 0);
}

bool AdminRepository::loadAdmin() {
    format fmt = format("SELECT * FROM `admins` WHERE `account` = '%d' LIMIT 1")
                 % player->getAccount()->getID();

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

    adminID_t id = atoi(row[ID]);
    player->getAdmin()->setID(id);

    Admin::AdminLevel level = Admin::AdminLevel(atoi(row[LEVEL]));
    player->getAdmin()->setLevel(level);

    string name = row[NAME];
    player->getAdmin()->setName(name);

    return true;
}

unsigned int AdminRepository::createAdmin(const Admin::AdminLevel level, const string& password) {
    format fmt = format("INSERT INTO `admins` (`account`, `level`, `password`) VALUES ('%d', '%d', MD5('%s'))")
                 % player->getAdmin()->getID() % level % password;

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    return connector.getInsertedID();
}

bool AdminRepository::destroyAdmin() {
    format fmt = format("DELETE FROM `admins` WHERE `id` = '%d' LIMIT 1")
                 % player->getAdmin()->getID();

    MySQLConnector connector(MainDatabase::getInstance());
    bool result = connector.query(fmt.str());

    return !result;
}

adminID_t AdminRepository::getID() const {
    format fmt = format(
            "SELECT `id` FROM `admins` WHERE `account` = '%d' LIMIT 1")
            % player->getAccount()->getID();

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

adminID_t AdminRepository::getID(const string& password) const {
    format fmt = format("SELECT `id` FROM `admins` WHERE `account` = '%d' AND `password` = MD5('%s') LIMIT 1")
                 % player->getAccount()->getID() % password;

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