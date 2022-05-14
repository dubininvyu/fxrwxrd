//
// Created by dubininvyu on 01.05.2022.
//

#include "LogsDatabase.h"

const string LogsDatabase::DATABASE_NAME = "main";

LogsDatabase::LogsDatabase() : Database(DATABASE_NAME) {

}

LogsDatabase::~LogsDatabase() {

}

LogsDatabase& LogsDatabase::getInstance() {
    static LogsDatabase database;
    return database;
}