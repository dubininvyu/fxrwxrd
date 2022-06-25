//
// Created by dubininvyu on 02.05.2022.
//


#pragma once

#include <string>

class Person;

using namespace std;

class PersonSex {
public:
    enum Sex {
        SEX_MALE = 0,
        SEX_FEMALE,

        sexMax
    };

    static const unsigned int MAX_COUNT = sexMax;
private:
protected:
    Person* person;

    string name;
    Sex sex;
public:
    PersonSex(Person* person);

    void setSex(const Sex sex);
    Sex getSex() const;

    bool isMale() const;
    bool isFemale() const;
};

