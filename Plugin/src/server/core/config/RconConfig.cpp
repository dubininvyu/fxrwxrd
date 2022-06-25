//
// Created by dubininvyu on 25.06.2022.
//

#include "RconConfig.h"

#include "logs.h"
#include "natives.h"

using namespace std;

RconConfig::rcon_params RconConfig::rconParams = {
        {PARAM_HOST_NAME, "hostname"},
        {PARAM_GAME_MODE_NAME, "gamemodetext"},
        {PARAM_MAP_NAME, "mapname"},
        {PARAM_GRAVITY, "gravity"},
        {PARAM_WEB_URL, "weburl"},
        {PARAM_RCON_PASSWORD, "rcon_password"},
        {PARAM_PASSWORD, "password"},
        {PARAM_LANGUAGE, "language"},
        {PARAM_MESSAGES_LIMIT, "messageslimit"},
        {PARAM_ASKS_LIMIT, "ackslimit"},
        {PARAM_MESSAGE_HOLE_LIMIT, "messageholelimit"},
        {PARAM_PLAYER_TIMEOUT, "playertimeout"},
};

RconConfig::config_params RconConfig::configParams = {};

/*
 * constructors & destructors
 */
RconConfig::RconConfig() : Config() {

}

RconConfig::~RconConfig() {

}

/*
 * methods
 * setters & getters
 */

void RconConfig::setParam(Param param, unsigned int value) {
    configParams[param] = value;

    if (param == PARAM_WEATHER) { // change weather
        api_server::native::SetWorldTime(value);
        return;
    }

    if (param == PARAM_WORLD_TIME) { // change world time
        api_server::native::SetWeather(value);
        return;
    }

    if (param > PARAM_RCON_START && param < PARAM_RCON_END) {
        setRconParam(param, to_string(value));
        return;
    }
}

void RconConfig::setParam(Param param, float value) {
    configParams[param] = value;

    if (param > PARAM_RCON_START && param < PARAM_RCON_END) {
        setRconParam(param, to_string(value));
        return;
    }
}

void RconConfig::setParam(Param param, string value) {
    configParams[param] = value;

    if (param > PARAM_RCON_START && param < PARAM_RCON_END) {
        setRconParam(param, value);
        return;
    }
}

type_variant& RconConfig::getParam(Param param) const {
    return configParams[param];
}

string RconConfig::getParamName(Param param) {
    return rconParams[param];
}

void RconConfig::setRconParam(Param param, string value) {
    string command = getParamName(param) + ' ' + value;

    api_server::native::SendRconCommand(command.c_str());
}