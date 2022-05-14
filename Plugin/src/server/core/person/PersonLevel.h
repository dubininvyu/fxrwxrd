//
// Created by dubininvyu on 02.05.2022.
//


#pragma once

class Person;

class PersonLevel {
public:
private:
protected:
    Person* person;
    unsigned int level;
public:
    PersonLevel(Person* person, const unsigned int level = 0);

    void increase();
    void decrease();

    void setLevel(const unsigned int level);
    unsigned int getLevel() const;

    unsigned int getUpdatedLevel() const;

    operator unsigned int();
};

