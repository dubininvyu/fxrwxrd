//
// Created by dubininvyu on 25.06.2022.
//


#pragma once

class Person;

class PersonAge {
public:
    enum Age {
        AGE_YOUNG = 0,
        AGE_ADULT,
        AGE_ELDERLY,

        ageMax
    };
private:
protected:
    Person* person;
    Age age;
public:
    PersonAge(Person* person);
    ~PersonAge();

    void setAge(const Age age);
    Age getAge() const;
};

