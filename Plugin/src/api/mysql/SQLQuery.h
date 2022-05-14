//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include <string>
#include <vector>

using namespace std;

class SQLQuery : std::vector<char> {
private:
protected:
    string query;
public:
    SQLQuery();
    SQLQuery(const string& string);
    ~SQLQuery();

    SQLQuery& operator()(const char* format);

    SQLQuery& operator<<(const char* string);
    SQLQuery& operator<<(const string& string);

    void setQuery(const string& query);
    string getQuery() const;
};

