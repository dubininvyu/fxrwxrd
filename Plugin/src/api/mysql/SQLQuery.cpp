//
// Created by dubininvyu on 01.05.2022.
//

#include "SQLQuery.h"
#include "SQLEvent.h"

SQLQuery::SQLQuery() : SQLQuery("") {

}

SQLQuery::SQLQuery(const string& string) : query(string), vector() {

}

SQLQuery::~SQLQuery() {

}

SQLQuery& SQLQuery::operator()(const char *format) {
    return *this;
}

SQLQuery& SQLQuery::operator<<(const char* string) { // escape strings
    if (!string) {
        return *this;
    }

    while (*string) {
        if (*string == '\'') {
            push_back('\\');
        }

        push_back(*string);

        string++;
    }

    return *this;
}

SQLQuery& SQLQuery::operator<<(const string& string) {
    if (string.empty()) {
        return *this;
    }

    for (auto i : string) {
        if (string[i] == '\'') {
            push_back('\\');
        }

        push_back(string[i]);
    }

    return *this;
}

void SQLQuery::setQuery(const string& query) {
    this->query = query;
}

string SQLQuery::getQuery() const {
    return query;
}