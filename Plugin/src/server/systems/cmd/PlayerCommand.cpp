//
// Created by dubininvyu on 13.05.2022.
//

#include "PlayerCommand.h"

PlayerCommand::mapCommands_type PlayerCommand::commands = {

};

PlayerCommand::PlayerCommand(Player* player, const string& params) : Command(player, params) {

}

Command* PlayerCommand::getCommand(Player* player, const string& command, const string& params) {
    if (!commands.count(command)) {
        return nullptr;
    }

    return commands[command](player, params);
}