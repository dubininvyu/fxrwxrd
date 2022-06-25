//
// Created by dubininvyu on 09.05.2022.
//

#include "Player.h"

#include "natives.h"
#include <functional>

bool Player::sendMessage(TextType text) const {
    return sendMessage(account->getLocale()->getText(text));
}

bool Player::sendMessage(const string &message) const {
    return api_server::native::SendClientMessage(this->id, -1, message.c_str());
}

bool Player::sendMessageToAll(TextType text) {
    bool result = true;

    Player::callEveryone([&](Player* player) {
        result &= player->sendMessage(text);
    });

    return result;
}

bool Player::sendMessageToAll(const string &message) {
    return api_server::native::SendClientMessageToAll(-1, message.c_str());
}