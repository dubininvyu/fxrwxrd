//
// Created by dubininvyu on 02.05.2022.
//

#include "PersonSkin.h"

#include "Person.h"
#include "natives.h"

PersonSkin::PersonSkin(const skinID_t skin) : PersonSkin(nullptr, skin) {

}

PersonSkin::PersonSkin(Person* person, const skinID_t skin) : person(person), skin(skin) {

}

void PersonSkin::setSkin(const skinID_t skin) {
    this->skin = skin;

    if (person != nullptr && person->isActive()) {
        api_server::native::SetPlayerSkin(this->person->getID(), this->skin);
    }
}

skinID_t PersonSkin::getSkin() const {
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

bool PersonSkin::isValid(const skinID_t skin) {
    return (skin >= MIN_ID && skin <= MAX_ID);
}