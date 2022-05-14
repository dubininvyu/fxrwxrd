//
// Created by dubininvyu on 02.05.2022.
//

#include "PersonName.h"

#include "Person.h"
#include "natives.h"

#include <string>

using namespace std;

PersonName::PersonName(Person* person) : person(person) {

}

void PersonName::setName(const string& name) {
    this->name = name;
    api_server::native::SetPlayerName(person->getID(), this->name.c_str());
}

string PersonName::getName() const {
    return name;
}

void PersonName::syncName() {
    char playerName[MAX_LENGTH];
    api_server::native::GetPlayerName(person->getID(), playerName, MAX_LENGTH);
    this->name = string(playerName);
}

bool PersonName::isValid() {
    return isValid(this->name);
}

bool PersonName::isValid(const string& name) {
    return true;
}