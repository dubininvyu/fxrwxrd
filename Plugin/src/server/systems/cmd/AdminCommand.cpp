//
// Created by dubininvyu on 13.05.2022.
//

#include "AdminCommand.h"
#include "admin/GotoCommand.h"

AdminCommand::mapCommands_type AdminCommand::commands = {
        {"goto",[](Player& player, const string& params) {return new GotoCommand(player, params);}},
};

AdminCommand::AdminCommand(Player& player, string params) : Command(player, params) {

}

Command* AdminCommand::getCommand(Player& player, const string& command, const string& params) {
    return commands[command](player, params);
}

void AdminCommand::setMinAdminRank(unsigned int minAdminRank) {
    this->minAdminRank = minAdminRank;
}

unsigned int AdminCommand::getMinAdminRank() {
    return this->minAdminRank;
}