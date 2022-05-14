//
// Created by dubininvyu on 01.05.2022.
//

#include "ErrorLog.h"

ErrorLog::ErrorLog(const string& message) : ErrorLog("", 0, message) {

}

ErrorLog::ErrorLog(const string& file, const unsigned long int line, const string& message) : Log(MARK, file, line, message) {

}

ErrorLog::~ErrorLog() {

}