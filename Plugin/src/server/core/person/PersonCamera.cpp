//
// Created by dubininvyu on 14.05.2022.
//

#include "PersonCamera.h"

#include "Person.h"
#include "natives.h"

PersonCamera::PersonCamera(Person* person) : person(person) {

}

bool PersonCamera::isPlayerSpectating() const {
    return (mode == MODE_ON);
}

bool PersonCamera::setSpectatingMode(SpectatingMode mode) {
    if (this->mode == mode) {
        return false;
    }

    this->mode = mode;
    return api_server::native::TogglePlayerSpectating(person->getID(), mode);
}