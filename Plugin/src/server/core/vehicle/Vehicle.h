//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "Player.h"
#include "Entity.h"

#include "geometry.h"

using namespace geometry;

class Vehicle : Entity {
public:
	static const int MIN_ID = 1;
	static const int MAX_ID = 2000;
	static const int MAX_COUNT = (MAX_ID - MIN_ID + 1);
	static const int INVALID_ID = 0xFFFF;
    static const int MAX_PARAMS = 8;

    enum Params {
        PARAM_ENGINE = 0,
        PARAM_LIGHTS,
        PARAM_ALARM,
        PARAM_DOORS,
        PARAM_BONNET,
        PARAM_BOOT,
        PARAM_OBJECTIVE,
        PARAM_SIREN
    };

    enum Damages {
        DAMAGE_PANELS = 0,
        DAMAGE_DOORS,
        DAMAGE_LIGHTS,
        DAMAGE_TIRES
    };

private:
protected:
    struct Data {
        bool engine;
        bool lights;
        bool alarm;
        bool doors;
        bool bonnet;
        bool boot;
        bool objective;
        bool siren;
    };

    struct Base {
        unsigned int model;
        vec4d pos;
        int color[2];
        int respawnDelay;
    };

    struct Damage {
        int panels;
        int doors;
        int lights;
        int tires;
    };

    // ======

	int id;
    int uid;

    Base base;
    Data data;
    Damage damage;

    static Vehicle* vehicles[MAX_COUNT];

    Vehicle(const unsigned int id, const Base& base, const Data& data);
public:
	~Vehicle();

	static Vehicle* create(const unsigned int model, const vec4d& pos, const int color[2], const int respawnDelay = -1, const bool siren = false);
	static void remove(Vehicle* vehicle);
	static Vehicle* get(const unsigned int vehicleID);

	bool isValid() const;
	static bool isValid(const unsigned int vehicleID);

	// vehicle params
	void setParams();
	void syncParams();

	void setParam(const Params param, bool value);
	bool getParam(const Params param) const;

	// vehicle damages
	void setDamages();
	void syncDamages();

	void setDamage(const Damages damage, bool value);
	bool getDamage(const Damages damage) const;
};