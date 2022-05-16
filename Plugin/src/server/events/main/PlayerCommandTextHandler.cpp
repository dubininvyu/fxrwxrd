//
// Created by dubininvyu on 03.05.2022.
//

#include "PlayerCommandTextHandler.h"

#include "texts.h"
#include "commands.h"

PlayerCommandTextHandler::PlayerCommandTextHandler(Player& player, const string& commandText) :
        PlayerEventHandler(player), command(commandText), params("") {

    command.erase(0, 1); // erase the first symbol ('/')

    stringstream ss(command);
    ss >> this->command;
    this->params = ss.str();
}

PlayerCommandTextHandler::~PlayerCommandTextHandler() {

}

bool PlayerCommandTextHandler::execute() {
    Command* cmd;

    if (!player.isActive()) {
        return false;
    }

    cmd = SystemCommand::getCommand(player, command, params);
    if (cmd) {
        return cmd->execute();
    }

    if (player.getAdmin()->isAdmin()) {
        cmd = AdminCommand::getCommand(player, command, params);
        return cmd->execute();
    }

    cmd = PlayerCommand::getCommand(player, command, params);
    if (cmd) {
        return cmd->execute();
    }

    player.sendMessage(player.getLocale()->getText(TEXT_UNKNOWN_COMMAND));

    return true;
}