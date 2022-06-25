//
// Created by dubininvyu on 15.05.2022.
//


#pragma once

#include <string>

using namespace std;

class Account;

class AccountPassword {
public:
    static const unsigned int MIN_LENGTH = 6;
    static const unsigned int MAX_LENGTH = 64;
private:
protected:
    Account* account;
    string password;
public:
    AccountPassword(Account* account, const string& password = "");

    bool setPassword(const string& password, const bool reWrite);
    string getPassword() const;

    bool isValid();
    static bool isValid(const string& password);
};

