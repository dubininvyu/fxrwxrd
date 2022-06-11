//
// Created by dubininvyu on 03.05.2022.
//

#include "PlayerIncomingConnectionHandler.h"

PlayerIncomingConnectionHandler::PlayerIncomingConnectionHandler(Player* player, const string& ip, const unsigned int port) :
    PlayerEventHandler(player), ip(ip), port(port) {

}

PlayerIncomingConnectionHandler::~PlayerIncomingConnectionHandler() {

}

bool PlayerIncomingConnectionHandler::execute() {
    return true;
}