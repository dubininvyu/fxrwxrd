//
// Created by dubininvyu on 13.05.2022.
//

#include "AdminCommand.h"
#include "admin_commands.h"

#define COMMAND(command, function)\
    {command, [](Player& player, const string& params) {return new function(player, params);}}

AdminCommand::mapCommands_type AdminCommand::commands = {
        COMMAND("goto", GotoCommand),
        COMMAND("sethp", SetHealthCommand),
};

AdminCommand::AdminCommand(Player& player, string params) : Command(player, params) {

}

Command* AdminCommand::getCommand(Player& player, const string& command, const string& params) {
    if (!commands.count(command)) {
        return nullptr;
    }

    return commands[command](player, params);
}

void AdminCommand::setMinAdminLevel(unsigned int minAdminLevel) {
    this->minAdminLevel = minAdminLevel;
}

unsigned int AdminCommand::getMinAdminLevel() const {
    return this->minAdminLevel;
}