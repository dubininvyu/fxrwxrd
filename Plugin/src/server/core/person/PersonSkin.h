//
// Created by dubininvyu on 02.05.2022.
//


#pragma once

#include "Item.h"

#include <string>

class Person;

using namespace std;

class PersonSkin {
public:
    constexpr static const unsigned int MIN_ID = 0;
    constexpr static const unsigned int MAX_ID = 299;
    constexpr static const unsigned int MAX_COUNT = (MAX_ID - MIN_ID + 1);

    enum SkinType {
        TYPE_CASUAL,
        TYPE_CLASSIC,
        TYPE_SLEEP,
        TYPE_BATH,
        TYPE_UNIFORM
    };
private:
protected:
    unsigned int skin;
    SkinType type;

    Person* person;
public:
    PersonSkin(const unsigned int skin = 0);
    PersonSkin(Person* person, const unsigned int skin = 0);

    void setSkin(const unsigned int skin);
    unsigned int getSkin() const;

    void syncSkin();

    SkinType getType() const;

    bool isValid();
    static bool isValid(const unsigned int skin);
};

