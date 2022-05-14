//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "PlayerEventHandler.h"

class PlayerCommandTextHandler : public PlayerEventHandler {
private:
protected:
    string command;
    string params;
public:
    PlayerCommandTextHandler(Player& player, const string& commandText);
    virtual ~PlayerCommandTextHandler();

    virtual bool execute();
};