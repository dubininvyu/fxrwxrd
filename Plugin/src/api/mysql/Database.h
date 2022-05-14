//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include <string>

using namespace std;

class Database {
public:
private:
protected:
    string host;
    string user;
    string password;
    string database;

    string socket;
    string charset;

    unsigned int port;
    unsigned long flag;

    string name; // database name
public:
    Database(const string& name);
    virtual ~Database();

    /* setters & getters */
    void setHost(const string& host);
    string getHost() const;

    void setUser(const string& user);
    string getUser() const;

    void setPassword(const string& password);
    string getPassword() const;

    void setDatabase(const string& database);
    string getDatabase() const;

    void setSocket(const string& socket);
    string getSocket() const;

    void setCharset(const string& charset);
    string getCharset() const;

    void setPort(const unsigned int port);
    unsigned int getPort() const;

    void setFlag(const unsigned long flag);
    unsigned long getFlag() const;

    void setName(const string& name);
    string getName() const;
};