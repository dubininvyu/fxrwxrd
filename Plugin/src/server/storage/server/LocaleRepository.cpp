//
// Created by dubininvyu on 10.05.2022.
//

#include "LocaleRepository.h"

#include "MySQLConnector.h"
#include "MainDatabase.h"
#include "boost/format.hpp"

#include <iostream>

using namespace std;
using namespace boost;

LocaleRepository::LocaleRepository(PlayerLocale& locale) : locale(locale), MySQLRepository() {

}

LocaleRepository::~LocaleRepository() {

}

bool LocaleRepository::init() {
    format fmt = format("SELECT `id`, `text` FROM `texts` WHERE `locale` = '%d' ORDER BY text_type ASC")
            % locale.getLanguage();

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(fmt.str());

    SQLResult result = connector.storeResult();
    if (!result) {
        return false;
    }

    size_t rows = result.getNumRows();

    if (!rows) {
        return false;
    }

    enum { ID = 0, TEXT };

    string text;
    unsigned int type;

    while (rows--) {
        MYSQL_ROW row = result.fetchRow();

        text = row[TEXT];
        type = atoi(row[ID]);

        string::size_type index;
        while ((index = text.find("\\n")) != string::npos) {
            text.replace(index, 2, "\n");
        }

        while ((index = text.find("\\t")) != string::npos) {
            text.replace(index, 2, "\t");
        }

        locale.setText(Text(type), text);
    }

    return true;
}