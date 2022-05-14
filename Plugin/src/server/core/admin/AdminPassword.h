//
// Created by dubininvyu on 15.05.2022.
//


#pragma once

#include <string>

class Admin;

using namespace std;

class AdminPassword {
public:
    static const unsigned int MIN_LENGTH = 4;
    static const unsigned int MAX_LENGTH = 128;
private:
protected:
    string password;
public:
    AdminPassword(const string& password = "");

    void setPassword(const string& password);
    string getPassword() const;

    bool isValid();
    static bool isValid(const string& password);
};

