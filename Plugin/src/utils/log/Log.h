//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include <string>

using namespace std;

class Log {
private:
protected:
    char mark;

    string file;
    unsigned long int line;

    string message;
public:
    Log(const char mark, const string& message);
    Log(const char mark, const string& file, const unsigned long int line, const string& message);
    virtual ~Log();

    void print();
};

