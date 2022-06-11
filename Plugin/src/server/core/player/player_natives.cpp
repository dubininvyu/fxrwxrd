//
// Created by dubininvyu on 09.05.2022.
//

#include "Player.h"

#include "natives.h"

bool Player::sendMessage(Text text) const {
    return sendMessage(getLocale()->getText(text));
}

bool Player::sendMessage(const string &message) const {
    return api_server::native::SendClientMessage(this->id, -1, message.c_str());
}

bool Player::sendMessageToAll(Text text) {
    return sendMessageToAll("It doesn't work! player_natives.cpp, line 18");
}

bool Player::sendMessageToAll(const string &message) {
    return api_server::native::SendClientMessageToAll(-1, message.c_str());
}