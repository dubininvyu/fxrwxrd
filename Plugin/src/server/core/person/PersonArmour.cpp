//
// Created by dubininvyu on 03.05.2022.
//

#include "PersonArmour.h"

#include "Person.h"
#include "natives.h"

PersonArmour::PersonArmour(const float armour) : PersonArmour(nullptr, armour) {

}

PersonArmour::PersonArmour(Person* person, const float armour) : person(person), armour(armour) {

}

void PersonArmour::setArmour(const float armour) {
    this->armour = armour;
    api_server::native::SetPlayerArmour(person->getID(), this->armour);
}

float PersonArmour::getArmour() const {
    return this->armour;
}

float PersonArmour::getUpdatedArmour() const {
    if (person == nullptr) {
        return 0.0;
    }

    float armour;
    api_server::native::GetPlayerArmour(person->getID(), armour);
    return armour;
}

bool PersonArmour::isValid() {
    return isValid(this->armour);
}

bool PersonArmour::isValid(const float armour) {
    return (armour >= MIN_ARMOUR && armour <= MAX_ARMOUR) || (armour == INF_ARMOUR);
}