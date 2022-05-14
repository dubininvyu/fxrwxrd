//
// Created by dubininvyu on 02.05.2022.
//


#pragma once

#include <string>

class Person;

using namespace std;

class PersonName {
public:
    constexpr static const unsigned int MAX_LENGTH = 24;
private:
protected:
    string name;
    Person* person;
public:
    PersonName(Person* person);

    void setName(const string& name);
    string getName() const;

    void syncName();

    bool isValid();
    static bool isValid(const string& name);
};

