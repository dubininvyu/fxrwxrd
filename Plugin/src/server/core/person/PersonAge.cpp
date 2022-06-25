//
// Created by dubininvyu on 25.06.2022.
//

#include "PersonAge.h"

PersonAge::PersonAge(Person* person) : person(person) {

}

PersonAge::~PersonAge() {

}

void PersonAge::setAge(const Age age) {
    this->age = age;
}

PersonAge::Age PersonAge::getAge() const {
    return age;
}