//
// Created by dubininvyu on 03.05.2022.
//

#include "PlayerTextHandler.h"

#include "PlayerCommandTextHandler.h"

PlayerTextHandler::PlayerTextHandler(Player& player, const string& text) :
        PlayerEventHandler(player) {

}

PlayerTextHandler::~PlayerTextHandler() {

}

bool PlayerTextHandler::executeLocalChat() {
    return true;
}

bool PlayerTextHandler::executeAdminChat() {
    return true;
}

bool PlayerTextHandler::executeGlobalChat() {
    return true;
}

bool PlayerTextHandler::execute() {
    if (text[0] == '.') { // this is a command
        text[0] = '/';
        return PlayerCommandTextHandler(player, text).execute();
    }

    if (text[0] == '=') { // this is a local chat
        return executeLocalChat();
    }

    if (text[0] == '!') { // this is an admin chat
        return executeAdminChat();
    }

    if (text[0] == '*') { // this is a global chat
        return executeGlobalChat();
    }

    return true;
}