//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "Database.h"

class LogsDatabase : public Database {
public:
    static const string DATABASE_NAME;
protected:
    LogsDatabase();
public:
    virtual ~LogsDatabase();

    static LogsDatabase& getInstance();
};

