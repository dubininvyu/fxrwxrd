//
// Created by dubininvyu on 01.05.2022.
//

#include "Person.h"
#include "ItemType.h"

/*
 * constructors & destructors
 */

Person::Person(const personID_t id, const bool active) : PrivateSubject(), id(id), active(active)
    /*Item(ItemType::TYPE_PERSON, "", 0.0, 0.0, 0.0, 0.0)*/ {

    age = new PersonAge(this);
    armour = new PersonArmour(this);
    camera = new PersonCamera(this);
    health = new PersonHealth(this);
    ip = new PersonIP(this);
    name = new PersonName(this);
    position = new PersonPosition(this);
    score = new PersonScore(this);
    sex = new PersonSex(this);
    skin = new PersonSkin(this);
    spawn = new PersonSpawn(this);
    team = new PersonTeam(this);
}

Person::~Person() {
    delete age;
    delete armour;
    delete camera;
    delete health;
    delete ip;
    delete name;
    delete position;
    delete score;
    delete sex;
    delete skin;
    delete spawn;
    delete team;
}

/*
 * setters & getters
 */
void Person::setID(const personID_t id){
    this->id = id;
}

personID_t Person::getID() const {
    return this->id;
}

void Person::setSpawned(const bool isSpawned) {
    this->spawned = isSpawned;
}

bool Person::isSpawned() const {
    return this->spawned;
}

void Person::setActive(const bool active) {
    this->active = active;
}

bool Person::isActive() const {
    return this->active;
}

PersonAge* Person::getAge() {
    return this->age;
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

PersonScore* Person::getScore() {
    return this->score;
}

PersonName* Person::getName() {
    return this->name;
}

PersonPosition* Person::getPosition() {
    return this->position;
}

PersonSex* Person::getSex() {
    return sex;
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