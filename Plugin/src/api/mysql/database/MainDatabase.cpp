//
// Created by dubininvyu on 01.05.2022.
//

#include "MainDatabase.h"

#include "DatabaseConfigRepository.h"

const string MainDatabase::DATABASE_NAME = "main";

MainDatabase::MainDatabase() : Database(DATABASE_NAME) {

}

MainDatabase::~MainDatabase() {

}

MainDatabase& MainDatabase::getInstance() {
    static MainDatabase database;
    return database;
}