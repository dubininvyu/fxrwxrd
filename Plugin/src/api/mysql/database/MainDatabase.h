//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "Database.h"

class MainDatabase : public Database {
public:
    static const string DATABASE_NAME;
protected:
    MainDatabase();
public:
    virtual ~MainDatabase();

    static MainDatabase& getInstance();
};

