//
// Created by dubininvyu on 11.05.2022.
//


#pragma once

#include <string>

using namespace std;

class Person;

class PersonIP {
public:
    static const unsigned int MAX_LENGTH = 16;
private:
protected:
    Person* person;
    string ip;
public:
    PersonIP(const string& ip);
    PersonIP(Person* person, const string& ip = "");

    void setIP(const string& ip);
    string getIP() const;

    void syncIP();
};

