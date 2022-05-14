//
// Created by dubininvyu on 03.05.2022.
//

#include "PlayerCommandTextHandler.h"

#include "texts.h"
#include "commands.h"

PlayerCommandTextHandler::PlayerCommandTextHandler(Player& player, const string& commandText) :
        PlayerEventHandler(player), command(commandText) {

    command.erase(0, 1); // erase the first symbol ('/')

    char cmd[28], args[100];
    sscanf(command.c_str(), "%27s %99c", cmd, args);

    this->command = string(cmd);
    this->params = string(args);
}

PlayerCommandTextHandler::~PlayerCommandTextHandler() {

}

bool PlayerCommandTextHandler::execute() {
    Command* cmd;

    cmd = SystemCommand::getCommand(player, command, params);
    if (cmd) {
        return cmd->execute();
    }

    if (!player.isActive()) {
        return false;
    }

    /*if (player.isAdmin()) {
        cmd = AdminCommand::getCommand(player, command, params);
        return cmd->execute();
    }*/

    cmd = PlayerCommand::getCommand(player, command, params);
    if (cmd) {
        return cmd->execute();
    }

    player.sendMessage(Text::TEXT_UNKNOWN_COMMAND);

    return true;
}