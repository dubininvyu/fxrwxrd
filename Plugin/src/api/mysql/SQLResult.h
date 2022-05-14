//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "mysql-conn/mysql.h"

#include <string>

using namespace std;

class SQLResult {
private:
protected:
    MYSQL_RES *result;
public:
    SQLResult(MYSQL_RES *result = nullptr);
    SQLResult(const SQLResult& result);

    operator bool();
    operator MYSQL_RES*();

    void free();

    int getNumRows();
    int getNumFields();

    MYSQL_ROW fetchRow();

    MYSQL_FIELD* fetch(const string& name);
    MYSQL_FIELD* fetchField();
};

