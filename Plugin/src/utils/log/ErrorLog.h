//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include "Log.h"

class ErrorLog : public Log {
private:
    static const char MARK = 'x';
protected:
public:
    ErrorLog(const string& message);
    ErrorLog(const string& file, const unsigned long int line, const string& message);

    virtual ~ErrorLog();
};

