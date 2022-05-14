//
// Created by dubininvyu on 01.05.2022.
//

#pragma once // SRV_CR_MYSQL_H

#include "SQLQuery.h"
#include "SQLResult.h"
#include "Database.h"

#include "mysql-conn/mysql.h"

#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std;

class MySQLConnector {
public:
private:
protected:
    MYSQL base;
	MYSQL* connection;
	Database& database;

    int errorID;
    int queryState;

    static MYSQL* connect(MYSQL *mysql, string host, string user,
            string password, string database, unsigned int port, string socket, unsigned long flag
    );

    static int setCharset(MYSQL *mysql, string charsetName);
public:
    MySQLConnector(Database& database);
    ~MySQLConnector();

    bool openConnection();
    bool closeConnection();

    bool query(const string& query);
    bool query(const SQLQuery& query);

    SQLResult useResult();
    SQLResult storeResult();

    unsigned long long getInsertedID() const;

    void setErrorID(const int errorID);
    int getErrorID() const;
};