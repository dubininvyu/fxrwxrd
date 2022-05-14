//
// Created by dubininvyu on 10.05.2022.
//

#include "PlayerRepository.h"

#include "Player.h"
#include "Exception.h"
#include "MainDatabase.h"

#include "boost/format.hpp"

using namespace std;
using namespace boost;

PlayerRepository::PlayerRepository(Player& player, const Mode mode) : MySQLRepository(), player(player), mode(mode) {
    if (mode & MODE_READ_ALL) {
        preload();
    }
}

PlayerRepository::~PlayerRepository() {

}

bool PlayerRepository::preload() {
    return true;
}

bool PlayerRepository::isRegistered() {
    format fmt = format("SELECT `id` FROM `accounts` WHERE `name` = '%s' LIMIT 1") % player.getName();

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    SQLResult result = connector.storeResult();
    if (!result) {
        return false;
    }

    return result.getNumRows() > 0;
}

bool PlayerRepository::loadAccount() {
    format fmt = format("SELECT * FROM `accounts` WHERE `id` = '%d' LIMIT 1")
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
        ID, NAME, PASSWORD, REGISTRATION_DATE, LAST_ONLINE_DATE, LOCALE, SEX, SKIN, LEVEL, HEALTH, ARMOUR
    };

    MYSQL_ROW row = result.fetchRow();

    Player::Sex sex = Player::Sex(atoi(row[SEX]));
    player.setSex(sex);

    PersonSkin* skin = player.getSkin();
    skin->setSkin(atoi(row[SKIN]));

    PersonLevel* level = player.getLevel();
    level->setLevel(atoi(row[LEVEL]));

    PersonHealth* health = player.getHealth();
    health->setHealth(stof(row[HEALTH]));

    PersonArmour* armour = player.getArmour();
    armour->setArmour(stof(row[ARMOUR]));
    return true;
}

unsigned int PlayerRepository::createAccount(const string& password, Player::Sex sex) {
    format fmt = format("INSERT INTO `accounts` (`name`, `password`, `sex`) VALUES ('%s', MD5('%s'), '%d')")
            % player.getName()->getName() % password % sex;

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    return connector.getInsertedID();
}

unsigned int PlayerRepository::getAccountID() const {
    format fmt = format(
            "SELECT `id` FROM `accounts` WHERE `name` = '%s' LIMIT 1")
            % player.getName()->getName();

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

unsigned int PlayerRepository::getAccountID(const string& password) const {
    format fmt = format("SELECT `id` FROM `accounts` WHERE `name` = '%s' AND `password` = MD5('%s') LIMIT 1")
                 % player.getName()->getName() % password;

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

Language PlayerRepository::getLanguage() const {
    if (!player.getUID()) {
        return LANGUAGE_RU;
    }

    format fmt = format(
            "SELECT `locale`, (SELECT `enabled` FROM `locales` WHERE `id` = `locale` LIMIT 1) FROM `accounts` WHERE `id` = '%d' LIMIT 1"
            ) % player.getUID();

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    SQLResult result = connector.storeResult();
    if (!result) {
        throw Exception(__FILE__, __LINE__, "Couldn't get locales data from the database");
    }

    if (!result.getNumRows()) {
        return LANGUAGE_DEFAULT;
    }

    enum {LOCALE, LOCALE_ENABLED};

    MYSQL_ROW row = result.fetchRow();

    unsigned int languageID = atoi(row[LOCALE]);
    bool isEnabled = atoi(row[LOCALE_ENABLED]);

    if (!isEnabled) {
        return LANGUAGE_DEFAULT;
    }

    return Language(languageID);
}