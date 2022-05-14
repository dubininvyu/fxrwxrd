//
// Created by dubininvyu on 01.05.2022.
//

#include "MySQLConnector.h"
#include "Exception.h"

MySQLConnector::MySQLConnector(Database& database) :
    connection(nullptr), database(database), errorID(0) {

    openConnection();
}

MySQLConnector::~MySQLConnector() {
    closeConnection();
}

bool MySQLConnector::openConnection() {
    string ERROR_TEXT = "Couldn't connect to the '" + database.getName() + "' database: ";

    if (mysql_init(&base) == nullptr) {
        throw Exception(__FILE__, __LINE__, ERROR_TEXT + "invalid MySQL initialization");
    }

    connection = connect(&base, database.getHost(), database.getUser(), database.getPassword(),
            database.getDatabase(), database.getPort(), database.getSocket(), database.getFlag()
    );

    if (!connection) {
        throw Exception(__FILE__, __LINE__, ERROR_TEXT + "invalid MySQL connection");
    }

    setCharset(connection, database.getCharset());
    mysql_set_server_option(connection, MYSQL_OPTION_MULTI_STATEMENTS_ON);

    return true;
}

bool MySQLConnector::closeConnection() {
    if (!connection) {
        return false;
    }

    mysql_close(connection);
    connection = nullptr;
    return true;
}

bool MySQLConnector::query(const string& query) {
    if (!connection) {
        errorID = -1;
        return false;
    }

    queryState = mysql_real_query(connection, query.c_str(), query.size());

    if (queryState) {
        errorID = mysql_errno(connection);
        throw Exception(__FILE__, __LINE__, "Couldn't execute MySQL query: " + query + " (error #" + to_string(errorID) + ")");
    }

    errorID = 0;
    return true;
}

bool MySQLConnector::query(const SQLQuery& query) {
    return this->query(query.getQuery());
}

SQLResult MySQLConnector::useResult() {
    if (!connection) {
        return nullptr;
    }

    MYSQL_RES* result = mysql_use_result(connection);

    if (!result) {
        return nullptr;
    }

    return result;
}

SQLResult MySQLConnector::storeResult() {
    if (!connection) {
        return nullptr;
    }

    MYSQL_RES* result = mysql_store_result(connection);

    if (!result) {
        return nullptr;
    }

    return result;
}

unsigned long long MySQLConnector::getInsertedID() const {
    return mysql_insert_id(connection);
}

MYSQL* MySQLConnector::connect(MYSQL *mysql, string host, string user,
                               string password, string database, unsigned int port, string socket, unsigned long flag) {

    return mysql_real_connect(mysql, host.c_str(), user.c_str(),
            password.c_str(), database.c_str(), port, socket.c_str(), flag
    );
}

int MySQLConnector::setCharset(MYSQL *mysql, string charsetName) {
    string query = "SET NAMES " + charsetName;
    return mysql_query(mysql, query.c_str());
}

void MySQLConnector::setErrorID(const int errorID) {
    this->errorID = errorID;
}

int MySQLConnector::getErrorID() const {
    return errorID;
}