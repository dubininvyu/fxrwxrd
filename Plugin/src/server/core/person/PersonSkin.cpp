//
// Created by dubininvyu on 02.05.2022.
//

#include "PersonSkin.h"

#include "Person.h"
#include "natives.h"

PersonSkin::PersonSkin(const unsigned int skin) : PersonSkin(nullptr, skin) {

}

PersonSkin::PersonSkin(Person* person, const unsigned int skin) : person(person), skin(skin) {

}

void PersonSkin::setSkin(const unsigned int skin) {
    this->skin = skin;

    if (person != nullptr && person->isActive()) {
        api_server::native::SetPlayerSkin(this->person->getID(), this->skin);
    }
}

unsigned int PersonSkin::getSkin() const {
    return skin;
}

void PersonSkin::syncSkin() {
    if (person == nullptr) {
        return;
    }

    this->skin = api_server::native::GetPlayerSkin(person->getID());
}

PersonSkin::SkinType PersonSkin::getType() const {
    return this->type;
}

bool PersonSkin::isValid() {
    return isValid(this->skin);
}

bool PersonSkin::isValid(const unsigned int skin) {
    return (skin >= MIN_ID && skin <= MAX_ID);
}