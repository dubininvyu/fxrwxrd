//
// Created by dubininvyu on 01.05.2022.
//

#include "FatalLog.h"

FatalLog::FatalLog(const string& message) : FatalLog("", 0, message) {

}

FatalLog::FatalLog(const string& file, const unsigned long int line, const string& message) : Log(MARK, file, line, message) {

}

FatalLog::~FatalLog() {

}