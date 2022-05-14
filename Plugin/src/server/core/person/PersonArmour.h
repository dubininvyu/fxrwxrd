//
// Created by dubininvyu on 03.05.2022.
//


#pragma once

class Person;

class PersonArmour {
public:
    constexpr static const float MIN_ARMOUR = 0.0;
    constexpr static const float MAX_ARMOUR = 100.0;
    constexpr static const float INF_ARMOUR = 0x7F800000;
private:
protected:
    float armour;
    Person* person;
public:
    PersonArmour(const float armour);
    PersonArmour(Person* person, const float armour = MIN_ARMOUR);

    void setArmour(const float armour);
    float getArmour() const;

    float getUpdatedArmour() const;

    bool isValid();
    static bool isValid(const float armour);
};

