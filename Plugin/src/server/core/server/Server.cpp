//
// Created by dubininvyu on 01.05.2022.
//

#include "Server.h"

#include "natives.h"

using namespace std;

Server::rcon_params Server::rconParams = {
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

Server::config_params Server::configParams = {};

Server::Server() {

}

Server::~Server() {

}

Server& Server::getInstance() {
	static Server server;
	return server;
}

void Server::setParam(CONFIG_PARAM param, unsigned int value) {
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

void Server::setParam(CONFIG_PARAM param, float value) {
    configParams[param] = value;

    if (param > PARAM_RCON_START && param < PARAM_RCON_END) {
        setRconParam(param, to_string(value));
        return;
    }
}

void Server::setParam(CONFIG_PARAM param, string value) {
    configParams[param] = value;

    if (param > PARAM_RCON_START && param < PARAM_RCON_END) {
        setRconParam(param, value);
        return;
    }
}

type_variant& Server::getParam(CONFIG_PARAM param) const {
    return configParams[param];
}

string Server::getParamName(CONFIG_PARAM param) {
    return rconParams[param];
}

void Server::setRconParam(Server::CONFIG_PARAM param, string value) {
    string command = getParamName(param) + ' ' + value;
    api_server::native::SendRconCommand(command.c_str());
}