//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "defines.h"

#include <map>
#include <string>
#include <variant>

using namespace std;

class Server {
public:
    enum CONFIG_PARAM {
        PARAM_NOPE = 0,

        PARAM_RCON_START,
        PARAM_HOST_NAME,
        PARAM_GAME_MODE_NAME,
        PARAM_MAP_NAME,
        PARAM_GRAVITY,
        PARAM_WEB_URL,
        PARAM_RCON_PASSWORD,
        PARAM_PASSWORD,
        PARAM_LANGUAGE,
        PARAM_MESSAGES_LIMIT,
        PARAM_ASKS_LIMIT,
        PARAM_MESSAGE_HOLE_LIMIT,
        PARAM_PLAYER_TIMEOUT,
        PARAM_RCON_END,

        PARAM_WEATHER,
        PARAM_WORLD_TIME,

        ENABLE_STUNT_BONUS_FOR_ALL,
        SHOW_NAME_TAGS,
        SHOW_PLAYER_MARKERS,
    };

private:
protected:
    typedef map<CONFIG_PARAM, type_variant> config_params;
    static config_params configParams;

    typedef map<CONFIG_PARAM, string> rcon_params;
    static rcon_params rconParams;

    Server();
public:
	~Server();

	static Server& getInstance();

    void setParam(CONFIG_PARAM param, unsigned int value);
    void setParam(CONFIG_PARAM param, float value);
    void setParam(CONFIG_PARAM param, string value);
    type_variant& getParam(CONFIG_PARAM param) const;

    static string getParamName(CONFIG_PARAM param);

    void setRconParam(CONFIG_PARAM param, string value);
};