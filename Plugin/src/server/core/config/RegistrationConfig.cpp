//
// Created by dubininvyu on 25.06.2022.
//

#include "RegistrationConfig.h"

#include "logs.h"
#include "natives.h"

using namespace std;

/*
 * constructors & destructors
 */
RegistrationConfig::RegistrationConfig() : Config() {

}

RegistrationConfig::~RegistrationConfig() {

}

/*
 * methods
 * setters & getters
 * skin
 */
void RegistrationConfig::addSkin(const skinID_t skin, const Sex sex, const Age age) {
    skins[sex][age].push_back(skin);
}

skinID_t RegistrationConfig::getSkin(const Sex sex, const Age age, const size_t index) {
    if (index >= 0 && index <= skins[sex][age].size()) {
        return 0;
    }

    return skins[sex][age].at(index);
}

skinID_t RegistrationConfig::getRandomSkin(const Sex sex, const Age age) {
    const size_t index = rand() % (skins[sex][age].size());
    return skins[sex][age].at(index);
}

/*
 * methods
 * setters & getters
 * health
 */
void RegistrationConfig::setHealth(const health_t health, const Sex sex, const Age age) {
    healths[sex][age] = health;
}

health_t RegistrationConfig::getHealth(const Sex sex, const Age age) {
    return healths[sex][age];
}