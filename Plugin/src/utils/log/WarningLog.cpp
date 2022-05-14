//
// Created by dubininvyu on 01.05.2022.
//

#include "WarningLog.h"

WarningLog::WarningLog(const string& message) : WarningLog("", 0, message) {

}

WarningLog::WarningLog(const string& file, const unsigned long int line, const string& message) : Log(MARK, file, line, message) {

}

WarningLog::~WarningLog() {

}