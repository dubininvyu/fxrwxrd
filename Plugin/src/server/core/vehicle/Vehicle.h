//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "Player.h"
#include "Entity.h"

#include "VehicleColor.h"
#include "VehicleDamage.h"
#include "VehicleModel.h"
#include "VehicleParam.h"
#include "VehiclePosition.h"

#include "geometry.h"

using namespace geometry;

class Vehicle : Entity {
public:
	static const int MIN_ID = 1;
	static const int MAX_ID = 2000;
	static const int MAX_COUNT = (MAX_ID - MIN_ID + 1);
	static const int INVALID_ID = 0xFFFF;

private:
protected:
    VehicleModel* model;
    VehicleColor* color;
    VehiclePosition* position;

    VehicleParam* param;
    VehicleDamage* damage;

    int respawnDelay;

    // ======
	unsigned int id;
    unsigned int uid;

    static Vehicle* vehicles[MAX_COUNT];

    Vehicle(const unsigned id, const unsigned model, const vec4d& position, const int colors[2], const int respawnDelay = -1, const bool siren = false);
public:
	~Vehicle();

	static Vehicle* create(const unsigned model, const vec4d& position, const int colors[2], const int respawnDelay = -1, const bool siren = false);
	static void remove(Vehicle* vehicle);
	static Vehicle* get(const unsigned int vehicleID);

	bool isValid() const;
	static bool isValid(const unsigned int vehicleID);

	void setID(const unsigned int id);
	unsigned int getID() const;

	void setUID(const unsigned int uid);
	unsigned int getUID() const;

	/* parts */
	VehicleColor* getColor();
    VehicleDamage* getDamage();
	VehicleModel* getModel();
	VehicleParam* getParam();
	VehiclePosition* getPosition();

};