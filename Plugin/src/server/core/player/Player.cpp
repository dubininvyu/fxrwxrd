//
// Created by dubininvyu on 01.05.2022.
//


#include "Player.h"

using namespace std;

const unsigned int Player::MAX_LENGTH_SERIAL = 40;

Player* Player::players[MAX_COUNT] = {nullptr};

Player::Player() : Person(INVALID_ID, false) {

}

Player::Player(unsigned int playerID) : Person(playerID, true) {
    spawned = false;
    authorized = false;

    // fields
    admin = new Admin(this);
    password = new PlayerPassword(this);

    // managers
    dialogManager = new DialogManager(this);
    stateMachineManager = new StateMachineManager(this);

    // systems
    locale = &PlayerLocale::getLocale(LANGUAGE_DEFAULT);
}

Player::~Player() {
    // fields
    delete admin;
    delete password;

    // managers
    delete dialogManager;
    delete stateMachineManager;

    // systems
}

Player* Player::create(const int playerID) {
    if (!isValid(playerID)) {
        return nullptr;
    }

    Player* player = new Player(playerID);
    players[playerID] = player;

    return player;
}

void Player::remove() const {
    Player* player = players[this->id];
    players[this->id] = nullptr;
    delete player;
}

Player* Player::get(const int playerID) {
    if (!isValid(playerID)) {
        return nullptr;
    }

    Player* player = players[playerID];
    if (!player) {
        return nullptr;
    }

    return player;
}

unsigned int Player::getCount() {
    unsigned int count = 0;

    for (Player* player : players) { // iterate array of players
        if (player == nullptr) { // there is no player in this locale
            continue;
        }

        count++;
    }

    return count;
}

bool Player::isValid() const {
    if (!isValid(this->id)) {
        return false;
    }

    for (Player *player : players) {
        if (player != this) {
            continue;
        }

        return true;
    }

    return false;
}

bool Player::isValid(const unsigned int playerID) {
    return (playerID >= MIN_ID && playerID <= MAX_ID);
}

/* setters & getters */
Admin* Player::getAdmin() {
    return this->admin;
}

void Player::setUID(const unsigned int uid) {
    this->uid = uid;
}
unsigned int Player::getUID() const {
    return this->uid;
}

/* main */
PlayerPassword* Player::getPassword() {
    return password;
}

void Player::setLocale(Language language) {
    this->locale = &PlayerLocale::getLocale(language);
}

PlayerLocale* Player::getLocale() const {
    return locale;
}

/* dynamic */
DialogManager* Player::getDialogManager() {
    return dialogManager;
}

StateMachineManager* Player::getStateMachineManager() {
    return stateMachineManager;
}

/* others */