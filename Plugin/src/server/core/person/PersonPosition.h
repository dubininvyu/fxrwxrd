//
// Created by dubininvyu on 10.05.2022.
//


#pragma once

#include "vec4d.h"

using namespace std;
using namespace geometry;

class Person;

class PersonPosition {
private:
protected:
    Person* person;
    vec4d position;

    int world;
    int interior;
public:
    PersonPosition();
    PersonPosition(Person* person);

    bool setPosition();
    bool setPosition(vec3d& position);
    bool setPosition(vec4d& position);

    bool setFacingAngle();
    bool setFacingAngle(float angle);

    void setWorld(int world);
    int getWorld() const;

    void setInterior(int interior);
    int getInterior() const;

    void syncPosition();
    vec4d& getPosition();
};

