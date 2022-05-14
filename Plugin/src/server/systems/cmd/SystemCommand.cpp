//
// Created by dubininvyu on 13.05.2022.
//

#include "SystemCommand.h"

SystemCommand::mapCommands_type SystemCommand::commands = {

};

SystemCommand::SystemCommand(Player& player, const string& params) : Command(player, params) {

}

Command* SystemCommand::getCommand(Player& player, const string& command, const string& params) {
    return commands[command](player, params);
}