//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "PlayerEventHandler.h"

class PlayerIncomingConnectionHandler : public PlayerEventHandler {
private:
protected:
    string ip;
    unsigned int port;
public:
    PlayerIncomingConnectionHandler(Player& player, const string& ip, const unsigned int port);
    virtual ~PlayerIncomingConnectionHandler();

    virtual bool execute();
};

