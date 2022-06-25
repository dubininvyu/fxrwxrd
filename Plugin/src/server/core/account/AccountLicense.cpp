//
// Created by dubininvyu on 12.06.2022.
//

#include "AccountLicense.h"

AccountLicense::AccountLicense(Account* account) : account(account) {

}

AccountLicense::~AccountLicense() {

}

void AccountLicense::setLicense(const License license, bool value) {
    if (isValid(license)) {
        return;
    }

    licenses[license] = value;
}

bool AccountLicense::isLicense(const License license) const {
    return licenses[license];
}

bool AccountLicense::isValid(const License license) const {
    return (license > LICENSE_NONE && license < COUNT);
}