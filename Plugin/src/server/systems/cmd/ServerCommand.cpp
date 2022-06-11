//
// Created by dubininvyu on 13.05.2022.
//

#include "ServerCommand.h"

ServerCommand::mapCommands_type ServerCommand::commands = {

};

ServerCommand::ServerCommand(Player* player, const string& params) : Command(player, params) {

}

Command* ServerCommand::getCommand(Player* player, const string& command, const string& params) {
    return commands[command](player, params);
}