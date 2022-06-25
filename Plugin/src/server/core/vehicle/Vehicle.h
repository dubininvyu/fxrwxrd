//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "Player.h"
#include "Entity.h"

#include "VehicleData.h"
#include "VehicleColor.h"
#include "VehicleDamage.h"
#include "VehicleModel.h"
#include "VehicleParam.h"
#include "VehiclePosition.h"

#include "geometry.h"

using namespace geometry;

typedef size_t vehicleID_t;

class Vehicle : protected virtual Item {
public:
	static const int MIN_ID = 1;
	static const int MAX_ID = 2000;
	static const int MAX_COUNT = (MAX_ID - MIN_ID + 1);
	static const int INVALID_ID = 0xFFFF;
private:
protected:
    /* basic vehicle data */
    VehicleModel* model = nullptr;
    VehicleColor* color = nullptr;
    VehiclePosition* position = nullptr;

    VehicleParam* param = nullptr;
    VehicleDamage* damage = nullptr;

    const int respawnDelay;

    /* extended vehicle data */
    vehicleID_t id;
    VehicleData* data;

    typedef map<vehicleID_t, Vehicle*> vehicles_map;
    static vehicles_map vehicles;

    Vehicle(const vehicleID_t id, const VehicleModel& model, const VehiclePosition& position, const VehicleColor& color, const int respawnDelay = -1, const bool siren = false);
public:
	~Vehicle();

	/*
	 * methods
	 * static
	 */
	static Vehicle* create(const VehicleModel& model, const VehiclePosition& position, const VehicleColor& color, const int respawnDelay = -1, const bool siren = false);
	static void destroy(Vehicle* vehicle);
	static Vehicle* get(const vehicleID_t vehicleID);

	bool isValid() const;
	static bool isValid(const vehicleID_t vehicleID);

	static bool isValidID(const vehicleID_t vehicleID);
	static bool isValidVehicle(const vehicleID_t vehicleID);

	/*
	 * methods
	 * setters & getters
	 */
	void setID(const vehicleID_t id);
    vehicleID_t getID() const;

    VehicleData* getData();

	VehicleColor* getColor();
    VehicleDamage* getDamage();
	VehicleModel* getModel();
	VehicleParam* getParam();
	VehiclePosition* getPosition();
};