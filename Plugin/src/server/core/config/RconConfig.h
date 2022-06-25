//
// Created by dubininvyu on 25.06.2022.
//


#pragma once

#include "Config.h"
#include "defines.h"

#include <map>

using namespace std;

class RconConfig : public virtual Config {
public:
    enum Param {
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
    typedef map<Param, type_variant> config_params;
    static config_params configParams;

    typedef map<Param, string> rcon_params;
    static rcon_params rconParams;
public:
    /*
     * constructors & destructors
     */
    RconConfig();
    virtual ~RconConfig();

    /*
     * methods
     * setters & getters
     */
    void setParam(Param param, unsigned int value);
    void setParam(Param param, float value);
    void setParam(Param param, string value);
    type_variant& getParam(Param param) const;

    static string getParamName(Param param);

    void setRconParam(Param param, string value);
};

