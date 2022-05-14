//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include "Log.h"

class InfoLog : public Log {
private:
    static const char MARK = '>';
protected:
public:
    InfoLog(const string& message);
    InfoLog(const string& file, const unsigned long int line, const string& message);
    virtual ~InfoLog();
};

