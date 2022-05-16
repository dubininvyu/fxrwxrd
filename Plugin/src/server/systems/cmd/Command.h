//
// Created by dubininvyu on 13.05.2022.
//

#pragma once

#include "Player.h"

#include "map"
#include "functional"

class Command {
private:

protected:
    Player& player;
    string params;

    typedef std::map<std::string, std::function<Command*(Player& player, const string& params)>> mapCommands_type;
public:
    Command(Player& player, const string& params);

    virtual bool execute() = 0;
};

