//
// Created by dubininvyu on 10.05.2022.
//

#include "PlayerSessionRepository.h"

#include "Player.h"
#include "MainDatabase.h"

#include "boost/format.hpp"

using namespace std;
using namespace boost;

PlayerSessionRepository::PlayerSessionRepository(Player* player) : PlayerRepository(player, MODE_NOPE) {

}

PlayerSessionRepository::~PlayerSessionRepository() {

}

unsigned long long PlayerSessionRepository::createSession(const int online, const string& ip) {
    format fmt = format("INSERT INTO `accounts_sessions` (`account`, `online`, `ip`) VALUES ('%d', '%d', '%s')")
                 % player->getUID() % player->getID() % player->getIP()->getIP();

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    return connector.getInsertedID();
}

bool PlayerSessionRepository::updateSession(const PlayerDisconnectHandler::Reason reason) {
    format fmt = format("UPDATE `accounts_sessions` SET `online` = '-1', `disconnect_reason` = '%d' WHERE `account` = '%d' AND `online` != -1")
                 % reason % player->getUID();

    MySQLConnector connector(MainDatabase::getInstance());
    bool result = connector.query(fmt.str());

    return !result;
}