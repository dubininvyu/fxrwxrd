//
// Created by dubininvyu on 12.06.2022.
//

#include "PlayerLicense.h"

PlayerLicense::PlayerLicense(Player* player) : player(player) {

}

PlayerLicense::~PlayerLicense() {

}

void PlayerLicense::setLicense(const License license, bool value) {
    if (isValid(license)) {
        return;
    }

    licenses[license] = value;
}

bool PlayerLicense::isLicense(const License license) const {
    return licenses[license];
}

bool PlayerLicense::isValid(const License license) const {
    return (license > LICENSE_NONE && license < COUNT);
}