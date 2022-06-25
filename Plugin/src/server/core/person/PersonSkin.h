//
// Created by dubininvyu on 02.05.2022.
//


#pragma once

#include "Item.h"

#include <string>

class Person;

using namespace std;

typedef size_t skinID_t;

class PersonSkin {
public:
    constexpr static const skinID_t MIN_ID = 0;
    constexpr static const skinID_t MAX_ID = 299;
    constexpr static const skinID_t MAX_COUNT = (MAX_ID - MIN_ID + 1);

    enum SkinType {
        TYPE_CASUAL,
        TYPE_CLASSIC,
        TYPE_SLEEP,
        TYPE_BATH,
        TYPE_UNIFORM
    };
private:
protected:
    skinID_t skin;
    SkinType type;

    Person* person;
public:
    PersonSkin(const skinID_t skin = 0);
    PersonSkin(Person* person, const skinID_t skin = 0);

    void setSkin(const skinID_t skin);
    skinID_t getSkin() const;

    void syncSkin();

    SkinType getType() const;

    bool isValid();
    static bool isValid(const skinID_t skin);
};

