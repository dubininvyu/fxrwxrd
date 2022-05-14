//
// Created by dubininvyu on 01.05.2022.
//

#include "InfoLog.h"

InfoLog::InfoLog(const string& message) : InfoLog("", 0, message) {

}

InfoLog::InfoLog(const string& file, const unsigned long int line, const string& message) : Log(MARK, file, line, message) {

}

InfoLog::~InfoLog() {

}