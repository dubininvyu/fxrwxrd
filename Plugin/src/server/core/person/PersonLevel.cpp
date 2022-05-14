//
// Created by dubininvyu on 02.05.2022.
//

#include "PersonLevel.h"

#include "Person.h"
#include "natives.h"

PersonLevel::PersonLevel(Person* person, const unsigned int level) : person(person), level(level) {

}

void PersonLevel::increase() {
    setLevel(this->level+1);
}

void PersonLevel::decrease() {
    setLevel(this->level-1);
}

void PersonLevel::setLevel(const unsigned int level) {
    this->level = level;
    api_server::native::SetPlayerScore(person->getID(), this->level);
}

unsigned int PersonLevel::getLevel() const {
    return api_server::native::GetPlayerScore(person->getID());
}

unsigned int PersonLevel::getUpdatedLevel() const {
    return api_server::native::GetPlayerScore(person->getID());
}

PersonLevel::operator unsigned int() {
    return getLevel();
}