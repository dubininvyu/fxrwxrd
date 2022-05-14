//
// Created by dubininvyu on 01.05.2022.
//

#include "Log.h"
#include "main.h"

#include <sstream>

Log::Log(const char mark, const string& message) : Log(mark, "", 0, message) {

}

Log::Log(const char mark, const string& file, const unsigned long int line, const string& message) :
    mark(mark), file(file), line(line), message(message) {

}

Log::~Log() {

}

void Log::print() {
    stringstream ss;

    ss << '[' << mark << ']' << ' ' << message;

    if (!file.empty()) {
        ss << ' ' << '[' << file << ' ' << '#' << line << ']';
    }

    api_server::logprintf(ss.str().c_str());
}