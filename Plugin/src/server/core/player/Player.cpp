//
// Created by dubininvyu on 01.05.2022.
//

#include "Player.h"
#include "ItemType.h"

using namespace std;

const unsigned int Player::MAX_LENGTH_SERIAL = 40;

size_t Player::count = 0;
Player* Player::players[MAX_COUNT] = {nullptr};

Player::Player() : Player(INVALID_ID, false) {

}

Player::Player(const personID_t id, const bool active) : Person(id, active)/*,
    Item(ItemType::TYPE_PERSON, "", 0.0, 0.0, 0.0, 0.0)*/ {

    spawned = false;
    authorized = false;

    if (id != INVALID_ID) {
        count++;

        // fields
        account = new Account(this);
        admin = new Admin(this);
        rconAdmin = new RconAdmin(this);

        // managers
        dialogManager = new DialogManager(this);
        stateMachineManager = new StateMachineManager(this);

        // systems
    }

}

Player::~Player() {
    if (id != INVALID_ID) {
        count--;

        // fields
        delete account;
        delete admin;
        delete rconAdmin;

        // managers
        delete dialogManager;
        delete stateMachineManager;

        // systems
    }
}

Player* Player::create(const personID_t id) {
    if (!isValid(id)) {
        return nullptr;
    }

    Player* player = new Player(id, true);
    players[id] = player;

    return player;
}

void Player::remove() const {
    Player* player = players[this->id];
    players[this->id] = nullptr;
    delete player;
}

Player* Player::get(const personID_t playerID) {
    if (!isValid(playerID)) {
        return nullptr;
    }

    Player* player = players[playerID];
    if (!player) {
        return nullptr;
    }

    return player;
}

const size_t Player::getCount() {
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

bool Player::isValid(const personID_t id) {
    return (id >= MIN_ID && id <= MAX_ID);
}

void Player::call(const function<void(Player*)> f) {
    f(this);
}

void Player::callEveryone(const function<void(Player*)> f) {
    for (Player* player : players) {
        f(player);
    }
}

/* setters & getters */


/* main */
Account* Player::getAccount() {
    return account;
}

Admin* Player::getAdmin() {
    return admin;
}

RconAdmin* Player::getRconAdmin() {
    return rconAdmin;
}

/* dynamic */
DialogManager* Player::getDialogManager() {
    return dialogManager;
}

StateMachineManager* Player::getStateMachineManager() {
    return stateMachineManager;
}

/* others */
void Player::setAuthorized(const bool isAuthorized) {
    authorized = isAuthorized;
}

bool Player::isAuthorized() const {
    return authorized;
}