//
// Created by dubininvyu on 10.05.2022.
//

#include "DatabaseConfigRepository.h"

#include "Exception.h"
#include "WarningLog.h"

using json = nlohmann::json;

const string DatabaseConfigRepository::DATABASE_CONFIG_FILE_PATH = "../Plugin/cfg/config_mysql.json";
const string DatabaseConfigRepository::CONFIG_NAME = "/mysql/";

DatabaseConfigRepository::DatabaseConfigRepository(const string& databaseName, Mode mode) :
    JsonRepository(DATABASE_CONFIG_FILE_PATH), databaseName(databaseName), mode(mode) {

    if (mode & MODE_READ_ALL) {
        preload();
    }
}

DatabaseConfigRepository::~DatabaseConfigRepository() {

}

bool DatabaseConfigRepository::preload() {
    if (!file.is_open()) {
        throw Exception(__FILE__, __LINE__, "Couldn't open MySQL config file '" + filePath + "'");
    }

    try {
        json = json::parse(file);
        file.close();
    }
    catch(json::exception& jsonException) {
        throw Exception(__FILE__, __LINE__, "JSON parse error: " + string(jsonException.what()));
    }

    return true;
}

bool DatabaseConfigRepository::init(Database& database) {
    database.setHost(this->getHost());
    database.setUser(this->getUser());

    database.setPassword(this->getPassword());
    database.setDatabase(this->getDatabase());

    database.setPort(this->getPort());
    database.setFlag(this->getFlag());

    database.setSocket(this->getSocket());
    database.setCharset(this->getCharset());

    return true;
}

string DatabaseConfigRepository::getHost() const {
    json::json_pointer jsonPointer(CONFIG_NAME + "connections/" + databaseName + "/host");

    if (isKeyExist(jsonPointer)) {
        return json.at(jsonPointer);
    }

    return "localhost";
}

string DatabaseConfigRepository::getUser() const {
    json::json_pointer jsonPointer(CONFIG_NAME + "connections/" + databaseName + "/user");

    if (isKeyExist(jsonPointer)) {
        return json.at(jsonPointer);
    }

    return "root";
}

string DatabaseConfigRepository::getPassword() const {
    json::json_pointer jsonPointer(CONFIG_NAME + "connections/" + databaseName + "/password");

    if (isKeyExist(jsonPointer)) {
        return json.at(jsonPointer);
    }

    return "";
}

string DatabaseConfigRepository::getDatabase() const {
    json::json_pointer jsonPointer(CONFIG_NAME + "connections/" + databaseName + "/database");

    if (isKeyExist(jsonPointer)) {
        return json.at(jsonPointer);
    }

    return "main";
}

unsigned int DatabaseConfigRepository::getPort() const {
    json::json_pointer jsonPointer(CONFIG_NAME + "connections/" + databaseName + "/port");

    if (isKeyExist(jsonPointer)) {
        return json.at(jsonPointer);
    }

    return 3306;
}

unsigned long DatabaseConfigRepository::getFlag() const {
    json::json_pointer jsonPointer(CONFIG_NAME + "connections/" + databaseName + "/client_flag");

    if (isKeyExist(jsonPointer)) {
        return json.at(jsonPointer);
    }

    return 0;
}

string DatabaseConfigRepository::getSocket() const {
    json::json_pointer jsonPointer(CONFIG_NAME + "connections/" + databaseName + "/unix_socket");

    if (isKeyExist(jsonPointer)) {
        return json.at(jsonPointer);
    }

    return "";
}

string DatabaseConfigRepository::getCharset() const {
    json::json_pointer jsonPointer(CONFIG_NAME + "charset");

    if (isKeyExist(jsonPointer)) {
        return json.at(jsonPointer);
    }

    return "cp1251";
}