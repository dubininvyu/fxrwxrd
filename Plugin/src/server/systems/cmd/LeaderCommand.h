//
// Created by dubininvyu on 13.05.2022.
//

#pragma once

#include "Command.h"

class LeaderCommand : public Command {
private:
protected:
    static mapCommands_type commands;

    LeaderCommand(Player* player, const string& params);
public:
    static Command* getCommand(Player* player, const string& command, const string& params);

    virtual bool execute() = 0;
};