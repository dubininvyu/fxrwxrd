//
// Created by dubininvyu on 09.05.2022.
//

#include "Player.h"

void Player::init() {
    /* name */
    this->getName()->syncName();

    /* ip */
    this->getIP()->syncIP();
}