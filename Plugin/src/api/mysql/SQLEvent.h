//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include <list>
#include <mutex>

#include "SQLResult.h"

class SQLQuery;
class MySQLConnector;

using namespace std;

class SQLEvent {
private:
protected:
    SQLEvent();
public:
    friend SQLQuery;
    friend MySQLConnector;

    virtual ~SQLEvent();
    virtual bool onQuery() = 0;
    virtual bool onExec(SQLResult& result) = 0;
};

