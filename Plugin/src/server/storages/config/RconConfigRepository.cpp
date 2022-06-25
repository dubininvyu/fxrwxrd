//
// Created by dubininvyu on 10.05.2022.
//

#include "RconConfigRepository.h"

#include "queries.h"

#include "Exception.h"
#include "json-parser/json.hpp"

#include "logs.h"
#include "databases.h"

#include <map>
#include <string>
#include <fstream>

using namespace std;
using json = nlohmann::json;

const string RconConfigRepository::CONFIG_PATH = "../Plugin/cfg/config_rcon.json";
const string RconConfigRepository::CONFIG_NAME = "/rcon/";

RconConfigRepository::map_params RconConfigRepository::params = {};

RconConfigRepository::RconConfigRepository(Mode mode) : MySQLRepository(mode) {
    if (mode & MODE_READ_ALL) {
        preload();
    }
}

RconConfigRepository::~RconConfigRepository() {

}

bool RconConfigRepository::preload() {
    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(MYSQL_QUERY_GET_CONFIG_RCON);

    SQLResult result = connector.storeResult();
    if (!result) {
        ErrorLog(__FILE__, __LINE__, "Couldn't load data from the database: invalid MySQL result").print();
        return "";
    }

    if (!result.getNumRows()) {
        ErrorLog(__FILE__, __LINE__, "Couldn't load data from the database: there is no rows").print();
        return "";
    }

    MYSQL_ROW row = result.fetchRow();
    size_t fields = result.getNumFields();

    for(size_t i = 0; i < fields; i++) {
        params[result.fetchField()->name] = row[i];
    }

    return true;
}

string RconConfigRepository::getParam(Param param) {
    if (!params.empty()) {
        return params[RconConfig::getParamName(param)];
    }

    return getDefaultParam(param);
}

string RconConfigRepository::getDefaultParam(Param param) {
    ifstream file(CONFIG_PATH);

    if (!file.is_open()) {
        ErrorLog(__FILE__, __LINE__, "Couldn't open rcon config file").print();

        return "";
    }

    json json = json::parse(file);

    if (file.is_open()) {
        file.close();
    }

    json::json_pointer jsonPointer(CONFIG_NAME + RconConfig::getParamName(param));
    if (!json.contains(jsonPointer)) {
        string message = "Couldn't setup server config (invalid key " + jsonPointer.to_string() + ") in rcon config";
        ErrorLog(__FILE__, __LINE__, message).print();

        return "";
    }

    try {
        return to_string(json.at(jsonPointer));
    }
    catch (json::exception & e) {
        const string message = "Couldn't parse json server config: " + string(e.what());
        ErrorLog(__FILE__, __LINE__, message).print();

        return "";
    }
}