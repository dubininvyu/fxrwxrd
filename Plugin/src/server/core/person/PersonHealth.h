//
// Created by dubininvyu on 03.05.2022.
//


#pragma once

class Person;

typedef float health_t;

class PersonHealth {
public:
    constexpr static const float MIN_HEALTH = 0.0;
    constexpr static const float MAX_HEALTH = 100.0;
    constexpr static const float INF_HEALTH = 0x7F800000;
private:
protected:
    float health;
    Person* person;
public:
    PersonHealth(Person* person, const float health = MIN_HEALTH);

    void setHealth(const float health);
    float getHealth() const;

    void syncHealth();

    bool isValid();
    static bool isValid(const float health);
};

