//
// Created by dubininvyu on 10.05.2022.
//

#include "LocaleRepository.h"
#include "MySQLConnector.h"

#include "logs.h"
#include "databases.h"

#include <iostream>
#include <boost/format.hpp>
#include <json-parser/json.hpp>

using namespace std;
using namespace boost;
using namespace nlohmann;

LocaleRepository::LocaleRepository(AccountLocale& locale) : locale(locale), MySQLRepository(MODE_NOPE) {

}

LocaleRepository::~LocaleRepository() {

}

bool LocaleRepository::preload() {
    return true;
}

size_t LocaleRepository::loadLocales() {
    string query = "SELECT *, (SELECT `name` FROM `accounts` a WHERE a.`id` = l.`developer`) AS `developer_name` FROM `locales` l";

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(query);

    SQLResult result = connector.storeResult();

    if (!result) {
        return 0;
    }

    size_t rows = result.getNumRows();
    if (!rows) {
        return 0;
    }

    enum {ID, LOCALE_NAME, ENABLED, DEVELOPER_ID, DEVELOPER_NAME};

    for (size_t i = 0; i < rows; i++) {
        MYSQL_ROW row = result.fetchRow();

        const Language language = Language(atoi(row[ID]));
        const string name = row[LOCALE_NAME];
        const bool enabled = atoi(row[ENABLED]);
        const string author = row[DEVELOPER_NAME];

        AccountLocale::addLocale(language, name, enabled, author);
    }

    return rows;
}

size_t LocaleRepository::loadTexts() {
    string query = "SELECT DISTINCT ";

    for (TextType i = TextType(textMin + 1); i != textMax; i = TextType(i + 1)) {
        string key = AccountLocale::getTextType(i);

        format fmt = format("(data ->> '$.%1%') AS `%1%`, ") % key;
        query += fmt.str();
    }

    query.erase(query.size() - 2); // delete last 2 symbols

    format fmt = format(" FROM `texts` WHERE `locale` = '%d' LIMIT 1") % locale.getLanguage();
    query += fmt.str();

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(query);

    SQLResult result = connector.storeResult();
    if (!result) {
        return 0;
    }

    if (!result.getNumRows()) {
        return 0;
    }

    enum { DATA };

    MYSQL_ROW row = result.fetchRow();

    const string controlSymbols[][2] = {
        {"\\n", "\n"},
        {"\\t", "\t"}
    };

    size_t fields = result.getNumFields();

    for (size_t i = 0; i < fields; i++) {
        MYSQL_FIELD* field = result.fetchField();

        TextType key = AccountLocale::getTextType(field->name);
        string text = row[i];

        size_t index = 0;

        for (size_t j = 0; j < sizeof(controlSymbols)/sizeof(controlSymbols[0]); j++) {
            while ((index = text.find(controlSymbols[j][0])) != string::npos) {
                text.replace(index, 2, controlSymbols[j][1]);
            }
        }

        locale.setText(key, text);
    }

    format string = format("Localization text strings loaded successfully (%d pcs)") % fields;
    InfoLog(__FILE__, __LINE__, string.str()).print();

    return fields;
}