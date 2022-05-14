//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include <string>
#include <stdexcept>

using namespace std;

class Exception {
private:
protected:
    string file;
    unsigned long int line;

    string error;
public:
    Exception(const string& file, unsigned long int line, const string& error) noexcept;
    virtual ~Exception() noexcept;

    void print() const;
};