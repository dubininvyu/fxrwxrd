//
// Created by dubininvyu on 10.05.2022.
//

#include "ServerRconConfigRepository.h"

#include "queries.h"
#include "ErrorLog.h"
#include "Exception.h"
#include "WarningLog.h"
#include "MainDatabase.h"

#include "json-parser/json.hpp"

#include <map>
#include <string>
#include <fstream>

using namespace std;
using json = nlohmann::json;

const string ServerRconConfigRepository::CONFIG_PATH = "../Plugin/cfg/config_rcon.json";
const string ServerRconConfigRepository::CONFIG_NAME = "/rcon/";

ServerRconConfigRepository::map_params ServerRconConfigRepository::params = {};

ServerRconConfigRepository::ServerRconConfigRepository(Mode mode) :
    MySQLRepository() {

    if (mode & MODE_READ_ALL) {
        preload();
    }
}

ServerRconConfigRepository::~ServerRconConfigRepository() {

}

bool ServerRconConfigRepository::preload() {
    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(MYSQL_QUERY_GET_CONFIG_RCON);

    SQLResult result = connector.storeResult();
    if (!result) {
        throw Exception(__FILE__, __LINE__, "Couldn't load data from the database: invalid MySQL Result");
    }

    if (result.getNumRows() == 0) {
        throw Exception(__FILE__, __LINE__, "Couldn't load data from the database: there is no rows");
    }

    MYSQL_ROW row = result.fetchRow();
    size_t fields = result.getNumFields();

    for(size_t i = 0; i < fields; i++) {
       params[result.fetchField()->name] = row[i];
    }

    return true;
}

string ServerRconConfigRepository::getParam(Server::CONFIG_PARAM param) {
    if (!params.empty()) {
        return params[Server::getParamName(param)];
    }

    return getDefaultParam(param);
}

string ServerRconConfigRepository::getDefaultParam(Server::CONFIG_PARAM param) {
    ifstream file(CONFIG_PATH);

    if (!file.is_open()) {
        throw Exception(__FILE__, __LINE__, "Couldn't open rcon config file");
    }

    json json = json::parse(file);

    if (file.is_open()) {
        file.close();
    }

    json::json_pointer jsonPointer(CONFIG_NAME + Server::getParamName(param));
    if (!json.contains(jsonPointer)) {
        throw Exception(__FILE__, __LINE__, "Couldn't setup server config (invalid key " + jsonPointer.to_string() + ") in rcon config");
    }

    try {
        return to_string(json.at(jsonPointer));
    }
    catch (json::exception & e) {
        throw Exception(__FILE__, __LINE__, e.what());
    }
}