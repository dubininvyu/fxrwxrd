//
// Created by dubininvyu on 13.05.2022.
//

#include "LeaderCommand.h"

LeaderCommand::mapCommands_type LeaderCommand::commands = {

};

LeaderCommand::LeaderCommand(Player* player, const string& params) : Command(player, params) {

}

Command* LeaderCommand::getCommand(Player* player, const string& command, const string& params) {
    return commands[command](player, params);
}