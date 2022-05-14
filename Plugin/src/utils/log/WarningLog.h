//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include "Log.h"

class WarningLog : public Log {
private:
    static const char MARK = '!';
protected:
public:
    WarningLog(const string& message);
    WarningLog(const string& file, const unsigned long int line, const string& message);
    virtual ~WarningLog();
};

