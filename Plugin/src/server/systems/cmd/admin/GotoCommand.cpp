//
// Created by dubininvyu on 13.05.2022.
//

#include "GotoCommand.h"

GotoCommand::GotoCommand(Player* player, const string& params) : AdminCommand(player, params) {

}

bool GotoCommand::execute() {
    player->sendMessage("This command is calling rn :)");
    return false;
}