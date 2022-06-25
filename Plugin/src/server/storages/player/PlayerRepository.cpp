    //
// Created by dubininvyu on 10.05.2022.
//

#include "PlayerRepository.h"

#include "Player.h"
#include "Server.h"
#include "Account.h"
#include "AccountLocale.h"
#include "Exception.h"

#include "logs.h"
#include "databases.h"

#include "boost/format.hpp"

using namespace std;
using namespace boost;

/*
 * constructors & destructors
 */
PlayerRepository::PlayerRepository(Player* player, const Mode mode) : MySQLRepository(mode), player(player) {

}

PlayerRepository::~PlayerRepository() {

}

/*
 * methods
 * virtual
 */

bool PlayerRepository::preload() {
    return true;
}

unsigned int PlayerRepository::load() {
    format fmt = format("SELECT * FROM `accounts` a LEFT JOIN accounts_positions ap ON a.`id` = `ap`.`account` WHERE a.`id` = '%d' LIMIT 1")
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
        // accounts
        ID, NAME, PASSWORD, REGISTRATION_DATE, LAST_ONLINE_DATE, LOCALE, SEX, AGE, SKIN, LEVEL, HEALTH, ARMOUR,
        // accounts_positions
        ID_, ACCOUNT, TIME, INTERIOR, WORLD, COORD_X, COORD_Y, COORD_Z, COORD_A
    };

    MYSQL_ROW row = result.fetchRow();

    // accounts
    PersonSex::Sex sex = PersonSex::Sex(atoi(row[SEX]));
    player->getSex()->setSex(sex);

    PersonAge::Age age = PersonAge::Age(atoi(row[AGE]));
    player->getAge()->setAge(age);

    PersonSkin* skin = player->getSkin();
    skin->setSkin(atoi(row[SKIN]));

    AccountLevel* level = player->getAccount()->getLevel();
    level->setLevel(atoi(row[LEVEL]));

    PersonHealth* health = player->getHealth();
    health->setHealth(stof(row[HEALTH]));

    PersonArmour* armour = player->getArmour();
    armour->setArmour(stof(row[ARMOUR]));

    // accounts_positions
    vec4d pos(
            stof(row[COORD_X]),
            stof(row[COORD_Y]),
            stof(row[COORD_Z]),
            stof(row[COORD_A])
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

accountID_t PlayerRepository::create(const string& name, const string& password, const Sex sex, const Age age) {

    RegistrationConfig* registrationConfig = Server::getInstance().getRegistrationConfig();

    skinID_t skin = registrationConfig->getRandomSkin(sex, age);
    health_t health = registrationConfig->getHealth(sex, age);

    string query = "INSERT INTO `accounts` (`name`, `password`, `sex`, `age`, `skin`, `health`) VALUES ('%s', MD5('%s'), '%d', '%d', '%d', '%f')";
    format fmt = format(query) % name % password % sex % age % skin % health;

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    return connector.getInsertedID();
}

/*
 * methods
 * for checking registration
 */
accountID_t PlayerRepository::getID() const {
    format fmt = format(
            "SELECT `id` FROM `accounts` WHERE `name` = '%s' LIMIT 1")
                 % player->getName()->getName();

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    SQLResult result = connector.storeResult();
    if (!result) {
        return Account::INVALID_ID;
    }

    if (!result.getNumRows()) {
        return Account::INVALID_ID;
    }

    enum {ID};

    MYSQL_ROW row = result.fetchRow();
    return atoi(row[ID]);
}

accountID_t PlayerRepository::getIDByPassword(const string& password) const {
    format fmt = format("SELECT `id` FROM `accounts` WHERE `name` = '%s' AND `password` = MD5('%s') LIMIT 1")
                 % player->getName()->getName() % password;

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    SQLResult result = connector.storeResult();
    if (!result) {
        return Account::INVALID_ID;
    }

    if (!result.getNumRows()) {
        return Account::INVALID_ID;
    }

    enum {ID};

    MYSQL_ROW row = result.fetchRow();
    return atoi(row[ID]);
}

Language PlayerRepository::getLocale() const {
    if (!player->getAccount()) {
        return LANGUAGE_DEFAULT;
    }

    format fmt = format(
            "SELECT `locale`, (SELECT `enabled` FROM `locales` WHERE `id` = `locale` LIMIT 1) FROM `accounts` WHERE `id` = '%d' LIMIT 1"
    ) % player->getAccount()->getID();

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

    locale_t languageID = atoi(row[LOCALE]);
    bool isEnabled = atoi(row[LOCALE_ENABLED]);

    if (!isEnabled) {
        return LANGUAGE_DEFAULT;
    }

    return Language(languageID);
}