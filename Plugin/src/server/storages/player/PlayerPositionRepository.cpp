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

/* main */
bool PlayerPositionRepository::preload() {
    return true;
}

unsigned int PlayerPositionRepository::save() {
    PersonPosition* position = player->getPosition();
    vec4d& coord = position->getPosition();

    format fmt = format("UPDATE `accounts_positions` SET `interior` = '%d', `world` = '%d', `coord_x` = '%f', `coord_y` = '%f', `coord_z` = '%f', `coord_a` = '%f' WHERE `account` = '%d' LIMIT 1")
                 % position->getInterior() % position->getWorld() % coord.getX() % coord.getY() % coord.getZ() % coord.getA() % player->getAccount()->getID();

    MySQLConnector connector(MainDatabase::getInstance());
    bool result = connector.query(fmt.str());

    return !result;
}

unsigned int PlayerPositionRepository::load() {
    return 0;
}

unsigned int PlayerPositionRepository::block() {
    return 0;
}

unsigned int PlayerPositionRepository::create() {
    format fmt = format("INSERT INTO `accounts_positions` (`account`) VALUES ('%d')")
                 % player->getAccount()->getID();

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    return connector.getInsertedID();
}

/* others */