//
// Created by dubininvyu on 01.05.2022.
//

#include "Vehicle.h"

#include "geometry.h"
#include "natives.h"

#include "event_handlers.h"

namespace native = api_server::native;

Vehicle* Vehicle::vehicles[MAX_COUNT] = {nullptr};

Vehicle::Vehicle(const unsigned id, const unsigned model, const vec4d& position, const int colors[2],  const int respawnDelay, const bool siren) :
    id(id), respawnDelay(respawnDelay) {

    this->color = new VehicleColor(this, colors);
    this->damage = new VehicleDamage(this);
    this->model = new VehicleModel(this, model);
    this->param = new VehicleParam(this);
    this->position = new VehiclePosition(this, position);
}

Vehicle::~Vehicle() {
    if (isValid()) {
        native::DestroyVehicle(id);
    }

    delete color;
    delete damage;
    delete model;
    delete param;
    delete position;
}

Vehicle* Vehicle::create(const unsigned model, const vec4d& position, const int colors[2], const int respawnDelay, const bool siren) {
	unsigned int vehicleID = native::CreateVehicle(model, position, colors[0], colors[1], respawnDelay, siren);

	if (!isValid(vehicleID)) {
	    return nullptr;
	}

	vehicles[vehicleID] = new Vehicle(vehicleID, model, position, colors, respawnDelay, siren);
	return vehicles[vehicleID];
}

void Vehicle::remove(Vehicle* vehicle) {
	vehicles[vehicle->id] = nullptr;
	delete vehicle;
}

Vehicle* Vehicle::get(unsigned int vehicleID) {
	Vehicle* vehicle = vehicles[vehicleID];

	if (!vehicle->isValid()) {
		return nullptr;
	}

	return vehicle;
}

bool Vehicle::isValid() const {
	if (!isValid(this->id)) {
		return false;
	}

	for (Vehicle* vehicle : vehicles) {
		if (vehicle != this) {
			continue;
		}

		return true;
	}

	return false;
}

bool Vehicle::isValid(const unsigned int vehicleID) {
	return (vehicleID >= MIN_ID && vehicleID <= MAX_ID);
}

// ===

void Vehicle::setID(const unsigned int id) {
    this->id = id;
}

unsigned int Vehicle::getID() const {
    return id;
}

void Vehicle::setUID(const unsigned int uid) {
    this->uid = uid;
}

unsigned int Vehicle::getUID() const {
    return uid;
}

/* parts */
VehicleColor* Vehicle::getColor() {
    return color;
}

VehicleDamage* Vehicle::getDamage() {
    return damage;
}

VehicleModel* Vehicle::getModel() {
    return model;
}

VehicleParam* Vehicle::getParam() {
    return param;
}

VehiclePosition* Vehicle::getPosition() {
    return position;
}

