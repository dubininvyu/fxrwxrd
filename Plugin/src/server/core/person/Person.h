//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include "PrivateSubject.h"

#include "PersonAge.h"
#include "PersonArmour.h"
#include "PersonCamera.h"
#include "PersonHealth.h"
#include "PersonIP.h"
#include "PersonName.h"
#include "PersonPosition.h"
#include "PersonScore.h"
#include "PersonSex.h"
#include "PersonSkin.h"
#include "PersonSpawn.h"
#include "PersonTeam.h"

#include "Item.h"

#include <string>

using namespace std;

typedef int personID_t;

class Person : public virtual PrivateSubject, virtual Item {
public:
    static const int INVALID_ID = 0xFFFF;
    static const unsigned int MIN_ID = 0;
    static const unsigned int MAX_ID = 499;
    static const unsigned int MAX_COUNT = (MAX_ID - MIN_ID + 1);
private:
protected:
    personID_t id;
    bool active;

    PersonAge* age;
    PersonArmour* armour;
    PersonCamera* camera;
    PersonHealth* health;
    PersonIP* ip;
    PersonName* name;
    PersonPosition* position;
    PersonScore* score;
    PersonSex* sex;
    PersonSkin* skin;
    PersonSpawn* spawn;
    PersonTeam* team;

    /* others */
    bool spawned;

    Person(const personID_t id, const bool active);
public:
    virtual ~Person();

    void setID(const personID_t id);
    personID_t getID() const;

    void setActive(const bool active);
    bool isActive() const;

    PersonAge* getAge();
    PersonArmour* getArmour();
    PersonCamera* getCamera();
    PersonHealth* getHealth();
    PersonIP* getIP();
    PersonName* getName();
    PersonPosition* getPosition();
    PersonScore* getScore();
    PersonSex* getSex();
    PersonSkin* getSkin();
    PersonSpawn* getSpawn();
    PersonTeam* getTeam();

    /* others */
    void setSpawned(const bool isSpawned);
    bool isSpawned() const;
};