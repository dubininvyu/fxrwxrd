//
// Created by dubininvyu on 01.05.2022.
//

#include "Person.h"

Person::Person(const int id, const bool active) : Animal(), LegalEntity(), TrackedEntity(),
    id(id), active(active) {

    armour = new PersonArmour(this);
    health = new PersonHealth(this);
    ip = new PersonIP(this);
    level = new PersonLevel(this);
    name = new PersonName(this);
    position = new PersonPosition(this);
    skin = new PersonSkin(this);
    spawn = new PersonSpawn(this);
    team = new PersonTeam(this);
    camera = new PersonCamera(this);
}

Person::~Person() {
    delete armour;
    delete health;
    delete ip;
    delete level;
    delete name;
    delete position;
    delete skin;
    delete spawn;
    delete team;
    delete camera;
}

/*void Person::setID(const int id){
    this->id = id;
}*/

int Person::getID() const {
    return this->id;
}

void Person::setActive(const bool active) {
    this->active = active;
}

bool Person::isActive() const {
    return this->active;
}

PersonArmour* Person::getArmour() {
    return this->armour;
}

PersonHealth* Person::getHealth() {
    return this->health;
}

PersonIP* Person::getIP() {
    return this->ip;
}

PersonLevel* Person::getLevel() {
    return this->level;
}

PersonName* Person::getName() {
    return this->name;
}

PersonPosition* Person::getPosition() {
    return this->position;
}

PersonSkin* Person::getSkin() {
    return this->skin;
}

PersonSpawn* Person::getSpawn() {
    return this->spawn;
}

PersonTeam* Person::getTeam() {
    return this->team;
}

PersonCamera* Person::getCamera() {
    return this->camera;
}

void Person::setSex(Sex sex) {
    this->sex = sex;
}

Person::Sex Person::getSex() const {
    return this->sex;
}

bool Person::isMale() const {
    return (sex == SEX_MALE);
}

bool Person::isFemale() const {
    return (sex == SEX_FEMALE);
}

/* others */
void Person::setSpawned(bool isSpawned) {
    this->spawned = isSpawned;
}

bool Person::isSpawned() const {
    return this->spawned;
}

void Person::setAuthorized(bool isAuthorized) {
    this->authorized = isAuthorized;
}

bool Person::isAuthorized() const {
    return this->authorized;
}