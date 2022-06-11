//
// Created by dubininvyu on 10.05.2022.
//


#pragma once

#include "PersonSkin.h"
#include "PersonTeam.h"
#include "PersonPosition.h"

class Person;

class PersonSpawn {
private:
protected:
    Person* person;

    PersonSkin skin;
    PersonTeam team;
    PersonPosition position;
public:
    PersonSpawn(Person* person);

    bool spawn();
    bool setSpawnInfo();

    PersonSkin& getSkin();
    PersonTeam& getTeam();
    PersonPosition& getPosition();
};

