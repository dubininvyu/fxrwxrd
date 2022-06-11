//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "JsonRepository.h"
#include "Database.h"

class DatabaseConfigRepository : public JsonRepository {
private:
    static const string DATABASE_CONFIG_FILE_PATH;
    static const string CONFIG_NAME;
public:
protected:
    string databaseName;
    Mode mode;
public:
    DatabaseConfigRepository(const string& databaseName, const Mode mode);
    virtual ~DatabaseConfigRepository();

    virtual bool preload();
    bool init(Database& database);

    string getHost() const;
    string getUser() const;
    string getPassword() const;
    string getDatabase() const;

    unsigned int getPort() const;
    unsigned long getFlag() const;

    string getSocket() const;
    string getCharset() const;
};

