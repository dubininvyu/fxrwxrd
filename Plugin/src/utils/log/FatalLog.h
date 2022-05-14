//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include "Log.h"

class FatalLog : public Log {
private:
    static const char MARK = 'x';
protected:
public:
    FatalLog(const string& message);
    FatalLog(const string& file, const unsigned long int line, const string& message);
    virtual ~FatalLog();
};

