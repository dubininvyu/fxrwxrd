//
// Created by dubininvyu on 01.05.2022.
//

#include "Exception.h"
#include "ErrorLog.h"

Exception::Exception(const string& file, unsigned long int line, const string& error) noexcept :
    file(file), line(line), error(error) {

}

Exception::~Exception() noexcept {

}

void Exception::print() const {
    ErrorLog(file, line, error).print();
}