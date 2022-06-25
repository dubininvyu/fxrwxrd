//
// Created by dubininvyu on 25.06.2022.
//


#pragma once

#include "Config.h"
#include "Person.h"


#include <vector>

using namespace std;

typedef PersonSex::Sex Sex;
typedef PersonAge::Age Age;

class RegistrationConfig : public Config {
public:
private:
protected:
    vector<skinID_t> skins[Sex::sexMax][Age::ageMax];
    float healths[Sex::sexMax][Age::ageMax];
public:
    /*
     * constructors & destructors
     */
    RegistrationConfig();
    virtual ~RegistrationConfig();

    /*
     * methods
     * setters & getters
     * skin
     */
    void addSkin(const skinID_t skin, const Sex sex, const Age age);
    skinID_t getSkin(const Sex sex, const Age age, const size_t index);

    skinID_t getRandomSkin(const Sex sex, const Age age);

    /*
     * methods
     * setters & getters
     * health
     */
    void setHealth(const health_t health, const Sex sex, const Age age);
    health_t getHealth(const Sex sex, const Age age);
};

