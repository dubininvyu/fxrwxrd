//
// Created by dubininvyu on 03.05.2022.
//

#include "PersonHealth.h"

#include "Person.h"
#include "natives.h"

PersonHealth::PersonHealth(Person* person, const float health) : person(person), health(health) {

}

void PersonHealth::setHealth(const float health) {
    this->health = health;
    api_server::native::SetPlayerHealth(person->getID(), this->health);
}

float PersonHealth::getHealth() const {
    return this->health;
}

void PersonHealth::syncHealth() {
    float playerHealth;
    api_server::native::GetPlayerHealth(person->getID(), playerHealth);
    this->health = playerHealth;
}

bool PersonHealth::isValid() {
    return isValid(this->health);
}

bool PersonHealth::isValid(const float health) {
    return (health >= MIN_HEALTH && health <= MAX_HEALTH) || (health == INF_HEALTH);
}