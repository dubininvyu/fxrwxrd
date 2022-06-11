//
// Created by dubininvyu on 13.05.2022.
//

#include "SetHealthCommand.h"

#include <string>
#include <boost/program_options.hpp>

using namespace std;
using namespace boost::program_options;

SetHealthCommand::SetHealthCommand(Player* player, const string& params) : AdminCommand(player, params) {
    try {
        split();
    }
    catch (...) {
        isHealth = false;
        isPlayerID = false;
    }
}

bool SetHealthCommand::execute() {
    if (!prepare()) {
        return false;
    }

    if (isHealth && isPlayerID && playerID == -1) {
        return setEveryoneHealth(health);
    }

    if (isHealth && !isPlayerID) {
        return setPlayerHealth(player, health);
    }

    Player* target = Player::get(playerID);
    setPlayerHealth(target, health);

    return true;
}

bool SetHealthCommand::prepare() {
    if(!isHealth && !isPlayerID) {
        return fail();
    }

    // check validness

    if (isHealth) {
        if (health == -1.0) {
            health = PersonHealth::INF_HEALTH;
        }

        if (!PersonHealth::isValid(health)) {
            return fail();
        }
    }
    else {
        health = PersonHealth::MAX_HEALTH;
    }

    if (isPlayerID) {
        if (!(playerID == -1 || Player::isValid(playerID))) {
            return fail();
        }
    }

    return true;
}

bool SetHealthCommand::fail() {
    player->sendMessage("Usage: /sethealth -h [health], -t [target]");
    return false;
}

void SetHealthCommand::split() {
    options_description description("Options");
    description.add_options()
            ("health,h", value<float>(&health)),
            ("target,t", value<int>(&playerID));

    variables_map map;
    store(command_line_parser(split_unix(params)).options(description).run(), map);
    notify(map);

    isHealth = map.count("health");
    isPlayerID = map.count("target");
}

bool SetHealthCommand::setEveryoneHealth(const float health) {
    return true;
}

bool SetHealthCommand::setPlayerHealth(Player* player, const float health) {
    player->getHealth()->setHealth(health);
    player->sendMessage("Your health had changed");
    return true;
}