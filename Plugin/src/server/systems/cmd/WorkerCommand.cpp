//
// Created by dubininvyu on 13.05.2022.
//

#include "WorkerCommand.h"

WorkerCommand::mapCommands_type WorkerCommand::commands = {
};

WorkerCommand::WorkerCommand(Player* player, const string& params) : Command(player, params) {

}

Command* WorkerCommand::getCommand(Player* player, const string& command, const string& params) {
    return commands[command](player, params);
}