//
// Created by dubininvyu on 01.05.2022.
//

#include "Database.h"
#include "DatabaseConfigRepository.h"

#include <fstream>

Database::Database(const string& name) : name(name) {
    DatabaseConfigRepository configRepository(name, Repository::MODE_READ_ALL);
    configRepository.init(*this);
}

Database::~Database() {

}

/* setters & getters */
void Database::setHost(const string& host) {
    this->host = host;
}

string Database::getHost() const {
    return this->host;
}

void Database::setUser(const string& user) {
    this->user = user;
}

string Database::getUser() const {
    return this->user;
}

void Database::setPassword(const string& password) {
    this->password = password;
}

string Database::getPassword() const {
    return this->password;
}

void Database::setDatabase(const string& database) {
    this->database = database;
}

string Database::getDatabase() const {
    return this->database;
}

void Database::setSocket(const string& socket) {
    this->socket = socket;
}

string Database::getSocket() const {
    return this->socket;
}

void Database::setCharset(const string& charset) {
    this->charset = charset;
}

string Database::getCharset() const {
    return this->charset;
}

void Database::setPort(const unsigned int port) {
    this->port = port;
}

unsigned int Database::getPort() const {
    return this->port;
}

void Database::setFlag(const unsigned long flag) {
    this->flag = flag;
}

unsigned long Database::getFlag() const {
    return this->flag;
}

void Database::setName(const string& name) {
    this->name = name;
}

string Database::getName() const {
    return name;
}