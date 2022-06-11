//
// Created by dubininvyu on 10.05.2022.
//

#include "PlayerPositionRepository.h"

#include "Player.h"
#include "MainDatabase.h"
#include "boost/format.hpp"

using namespace std;
using namespace boost;

PlayerPositionRepository::PlayerPositionRepository(Player* player) : PlayerRepository(player, MODE_NOPE) {

}

PlayerPositionRepository::~PlayerPositionRepository() {

}

unsigned int PlayerPositionRepository::createPosition() {
    format fmt = format("INSERT INTO `accounts_positions` (`account`) VALUES ('%d')")
                 % player->getUID();

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    return connector.getInsertedID();
}

bool PlayerPositionRepository::loadPosition() {
    format fmt = format("SELECT * FROM `accounts_positions` WHERE `account` = '%d' LIMIT 1")
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
        ID, PLAYER_ID, TIME, INTERIOR, WORLD, COORD_X, COORD_Y, COORD_Z, COORD_A
    };

    MYSQL_ROW row = result.fetchRow();

    float x = stof(row[COORD_X]);
    float y = stof(row[COORD_Y]);
    float z = stof(row[COORD_Z]);
    float a = stof(row[COORD_A]);
    vec4d pos(x, y, z, a);

    PersonSpawn* spawn = player->getSpawn();
    spawn->getPosition().setPosition(pos);
    spawn->getPosition().setWorld(stof(row[WORLD]));
    spawn->getPosition().setInterior(stof(row[INTERIOR]));

    return true;
}

bool PlayerPositionRepository::savePosition(PersonPosition* position) {
    vec4d& pos = position->getPosition();

    format fmt = format("UPDATE `accounts_positions` SET `interior` = '%d', `world` = '%d', `coord_x` = '%f', `coord_y` = '%f', `coord_z` = '%f', `coord_a` = '%f' WHERE `account` = '%d' LIMIT 1")
                 % position->getInterior() % position->getWorld() % pos.getX() % pos.getY() % pos.getZ() % pos.getA() % player->getUID();

    MySQLConnector connector(MainDatabase::getInstance());
    bool result = connector.query(fmt.str());

    return !result;
}