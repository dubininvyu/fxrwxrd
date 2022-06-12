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

PlayerRepository::PlayerRepository(Player* player, const Mode mode) : MySQLRepository(), player(player), mode(mode) {
    if (mode & MODE_READ_ALL) {
        preload();
    }
}

PlayerRepository::~PlayerRepository() {

}

/* main */

bool PlayerRepository::preload() {
    return true;
}

unsigned int PlayerRepository::load() {
    format fmt = format("SELECT * FROM `accounts` a LEFT JOIN accounts_positions ap ON a.`id` = `ap`.`account` WHERE a.`id` = '%d' LIMIT 1")
                 % player->getUID();

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
        // accounts
        ID, NAME, PASSWORD, REGISTRATION_DATE, LAST_ONLINE_DATE, LOCALE, SEX, SKIN, LEVEL, HEALTH, ARMOUR,
        // accounts_positions
        ID_, ACCOUNT, TIME, INTERIOR, WORLD, COORD_X, COORD_Y, COORD_Z, COORD_A
    };

    MYSQL_ROW row = result.fetchRow();

    // accounts
    PersonSex::Sex sex = PersonSex::Sex(atoi(row[SEX]));
    player->getSex()->setSex(sex);

    PersonSkin* skin = player->getSkin();
    skin->setSkin(atoi(row[SKIN]));

    PersonLevel* level = player->getLevel();
    level->setLevel(atoi(row[LEVEL]));

    PersonHealth* health = player->getHealth();
    health->setHealth(stof(row[HEALTH]));

    PersonArmour* armour = player->getArmour();
    armour->setArmour(stof(row[ARMOUR]));

    // accounts_positions
    vec4d pos(
            stof(row[COORD_X]),
            stof(row[COORD_X]),
            stof(row[COORD_X]),
            stof(row[COORD_X])
    );

    PersonSpawn* spawn = player->getSpawn();
    spawn->getPosition().setPosition(pos);
    spawn->getPosition().setWorld(stof(row[WORLD]));
    spawn->getPosition().setInterior(stof(row[INTERIOR]));

    return atoi(row[ID]);
}

unsigned int PlayerRepository::block() {
    return 0;
}

unsigned int PlayerRepository::update() {
    return 0;
}

unsigned int PlayerRepository::create() {
    format fmt = format("INSERT INTO `accounts` (`name`, `password`, `sex`) VALUES ('%s', MD5('%s'), '%d')")
                 % player->getName()->getName() % player->getPassword()->getPassword() % player->getSex()->getSex();

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    return connector.getInsertedID();
}

/* is ... */
bool PlayerRepository::isRegistered() const {
    return (getUID() > 0);
}

bool PlayerRepository::isRegisteredByPassword(const string& password) const {
    return (getUIDByPassword(password) > 0);
}


/* get uid */
unsigned int PlayerRepository::getUID() const {
    format fmt = format(
            "SELECT `id` FROM `accounts` WHERE `name` = '%s' LIMIT 1")
                 % player->getName()->getName();

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

unsigned int PlayerRepository::getUIDByPassword(const string& password) const {
    format fmt = format("SELECT `id` FROM `accounts` WHERE `name` = '%s' AND `password` = MD5('%s') LIMIT 1")
                 % player->getName()->getName() % password;

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

/* others */

Language PlayerRepository::getLanguage() const {
    if (!player->getUID()) {
        return LANGUAGE_DEFAULT;
    }

    format fmt = format(
            "SELECT `locale`, (SELECT `enabled` FROM `locales` WHERE `id` = `locale` LIMIT 1) FROM `accounts` WHERE `id` = '%d' LIMIT 1"
            ) % player->getUID();

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