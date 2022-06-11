//
// Created by dubininvyu on 13.05.2022.
//

#pragma once

#include "Command.h"

class AdminCommand : public Command {
private:
protected:
    unsigned int minAdminLevel;

    static mapCommands_type commands;

    AdminCommand(Player* player, const string params);
public:
    static Command* getCommand(Player* player, const string& command, const string& params);

    virtual bool execute() = 0;

    void setMinAdminLevel(unsigned int minAdminLevel);
    unsigned int getMinAdminLevel() const;
};