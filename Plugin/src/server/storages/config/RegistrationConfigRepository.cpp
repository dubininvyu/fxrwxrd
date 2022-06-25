//
// Created by dubininvyu on 10.05.2022.
//

#include "RegistrationConfigRepository.h"

#include "PersonAge.h"
#include "PersonSex.h"

#include "services.h"

#include "logs.h"
#include "databases.h"

#include <string>

using namespace std;
using json = nlohmann::json;

typedef PersonSex::Sex Sex;
typedef PersonAge::Age Age;

RegistrationConfigRepository::RegistrationConfigRepository(Mode mode) : MySQLRepository(mode) {

    if (mode & MODE_READ_ALL) {
        preload();
    }
}

RegistrationConfigRepository::~RegistrationConfigRepository() {

}

bool RegistrationConfigRepository::preload() {
    return true;
}

bool RegistrationConfigRepository::load() {
    MySQLConnector connector(MainDatabase::getInstance());
    connector.query("SELECT `data` FROM `configs` WHERE `type` = 'registration' LIMIT 1");

    SQLResult result = connector.storeResult();
    if (!result) {
        ErrorLog(__FILE__, __LINE__, "Couldn't load registration data config from the database: invalid MySQL Result").print();
        return false;
    }

    if (!result.getNumRows()) {
        ErrorLog(__FILE__, __LINE__, "Couldn't load registration data config from the database: there is no rows").print();
        return false;
    }

    MYSQL_ROW row = result.fetchRow();

    enum {DATA};

    RegistrationConfig* config = Server::getInstance().getRegistrationConfig();

    const string REGISTRATION = "registration";
    const string DEFAULT_SKINS = "default_skins";
    const string DEFAULT_HEALTHS = "default_healths";

    const string sexes[] = {
            "male",
            "female"
    };

    const string ages[] = {
            "young",
            "adult",
            "elderly"
    };

    try {
        nlohmann::json json = json::parse(row[DATA]);
        nlohmann::json jsonSkin = json[REGISTRATION][DEFAULT_SKINS];
        nlohmann::json jsonHealth = json[REGISTRATION][DEFAULT_HEALTHS];

        for (Sex sex = Sex::SEX_MALE; sex != Sex::sexMax; sex = Sex(sex + 1)) {
            for (Age age = Age::AGE_YOUNG; age != Age::ageMax; age = Age(age + 1)) {

                string ageName = ages[age];
                string sexName = sexes[sex];

                // skins
                size_t nSkins = jsonSkin[sexName][ageName].size();
                for (size_t i = 0; i < nSkins; i++) {
                    skinID_t skin = jsonSkin[sexName][ageName][i];
                    config->addSkin(skin, sex, age);
                }

                // healths
                health_t health = jsonHealth[sexName][ageName];
                config->setHealth(health, sex, age);
            }
        }
    }
    catch (const json::exception& exception) {
        string message = "Couldn't parse registration config data: " + string(exception.what());
        ErrorLog(__FILE__, __LINE__, message).print();
        return false;
    }

    return true;
}