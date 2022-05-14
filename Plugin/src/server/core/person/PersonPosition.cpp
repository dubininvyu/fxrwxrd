//
// Created by dubininvyu on 10.05.2022.
//

#include "PersonPosition.h"

#include "Person.h"
#include "natives.h"

using namespace geometry;

PersonPosition::PersonPosition() : PersonPosition(nullptr) {

}

PersonPosition::PersonPosition(Person* person) : person(person), position(0, 0, 0, 0) {

}

bool PersonPosition::setPosition() {
    if (person == nullptr) {
        return false;
    }

    return api_server::native::SetPlayerPos(person->getID(), position);
}

bool PersonPosition::setPosition(vec3d& position) {
    this->position = position;
    return setPosition();
}

bool PersonPosition::setPosition(vec4d& position) {
    bool allow = true;

    allow &= setPosition((vec3d&) position);
    allow &= setFacingAngle(position.getA());

    return allow;
}

bool PersonPosition::setFacingAngle() {
    if (person == nullptr) {
        return false;
    }

    return api_server::native::SetPlayerFacingAngle(person->getID(), position.getA());
}

bool PersonPosition::setFacingAngle(float angle) {
    this->position.setA(angle);
    return setFacingAngle();
}

void PersonPosition::setWorld(int world) {
    this->world = world;

    if (person != nullptr) {
        api_server::native::SetPlayerVirtualWorld(person->getID(), this->world);
    }
}

int PersonPosition::getWorld() const {
    return this->world;
}

void PersonPosition::setInterior(int interior) {
    this->interior = interior;

    if (person != nullptr) {
        api_server::native::SetPlayerInterior(person->getID(), this->interior);
    }
}

int PersonPosition::getInterior() const {
    return this->interior;
}

vec4d& PersonPosition::getPosition() {
    return position;
}

#include "InfoLog.h"
void PersonPosition::syncPosition() {
    if (person == nullptr) {
        return;
    }

    api_server::native::GetPlayerPos(person->getID(), position);

    float r;
    api_server::native::GetPlayerFacingAngle(person->getID(), r);
    position.setA(r);

    this->world = api_server::native::GetPlayerVirtualWorld(person->getID());
    this->interior = api_server::native::GetPlayerInterior(person->getID());
}