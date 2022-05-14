//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include "Animal.h"
#include "LegalEntity.h"
#include "TrackedEntity.h"

#include "PersonArmour.h"
#include "PersonHealth.h"
#include "PersonIP.h"
#include "PersonLevel.h"
#include "PersonName.h"
#include "PersonPosition.h"
#include "PersonSkin.h"
#include "PersonSpawn.h"
#include "PersonTeam.h"
#include "PersonCamera.h"

#include <string>


using namespace std;

class Person : Animal, LegalEntity, TrackedEntity {
public:
    static const int INVALID_ID = 0xFFFF;
    static const unsigned int MIN_ID = 0;
    static const unsigned int MAX_ID = 499;
    static const unsigned int MAX_COUNT = (MAX_ID - MIN_ID + 1);

    enum Sex {
        SEX_MALE = 0,
        SEX_FEMALE
    };
private:
protected:
    int id;
    bool active;

    PersonArmour* armour;
    PersonHealth* health;
    PersonIP* ip;
    PersonLevel* level;
    PersonName* name;
    PersonPosition* position;
    PersonSkin* skin;
    PersonSpawn* spawn;
    PersonTeam* team;
    PersonCamera* camera;

    Sex sex;

    /* others */
    bool spawned;
    bool authorized;

    Person(const int id, const bool active);
public:
    virtual ~Person();

    void setID(const int id) = delete;
    int getID() const;

    void setActive(const bool active);
    bool isActive() const;

    PersonArmour* getArmour();
    PersonHealth* getHealth();
    PersonIP* getIP();
    PersonLevel* getLevel();
    PersonName* getName();
    PersonPosition* getPosition();
    PersonSkin* getSkin();
    PersonSpawn* getSpawn();
    PersonTeam* getTeam();
    PersonCamera* getCamera();

    /* sex */
    void setSex(Sex sex);
    Sex getSex() const;

    bool isMale() const;
    bool isFemale() const;

    /* others */
    void setSpawned(bool isSpawned);
    bool isSpawned() const;

    void setAuthorized(bool isAuthorized);
    bool isAuthorized() const;
};