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
#include "PersonSex.h"
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
    PersonSex* sex;
    PersonSkin* skin;
    PersonSpawn* spawn;
    PersonTeam* team;
    PersonCamera* camera;

    /* others */
    bool spawned;
    bool authorized;

    Person(const int id, const bool active);
public:
    virtual ~Person();

    void setID(const int id);
    int getID() const;

    void setActive(const bool active);
    bool isActive() const;

    PersonArmour* getArmour();
    PersonHealth* getHealth();
    PersonIP* getIP();
    PersonLevel* getLevel();
    PersonName* getName();
    PersonPosition* getPosition();
    PersonSex* getSex();
    PersonSkin* getSkin();
    PersonSpawn* getSpawn();
    PersonTeam* getTeam();
    PersonCamera* getCamera();

    /* others */
    void setSpawned(bool isSpawned);
    bool isSpawned() const;

    void setAuthorized(bool isAuthorized);
    bool isAuthorized() const;
};