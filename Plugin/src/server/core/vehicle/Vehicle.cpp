//
// Created by dubininvyu on 01.05.2022.
//

#include "Vehicle.h"

#include "geometry.h"
#include "event_handlers.h"

#include "logs.h"
#include "natives.h"

#include "boost/format.hpp"

using namespace boost;

namespace native = api_server::native;

typedef VehicleColor::Color Color;

Vehicle::vehicles_map Vehicle::vehicles;

/*
 * constructors & destructors
 */
Vehicle::Vehicle(const vehicleID_t id, const VehicleModel& model, const VehiclePosition& position, const VehicleColor& color, const int respawnDelay, const bool siren) :
    id(id), respawnDelay(respawnDelay) {

    this->damage = new VehicleDamage(this); // vehicle damage data
    this->param = new VehicleParam(this); // vehicle param data
    this->data = new VehicleData(this); // personal vehicle data

    if (isValid(id)) {
        this->model = new VehicleModel(this, model); // copy constructor
        this->position = new VehiclePosition(this, position); // copy constructor
        this->color = new VehicleColor(this, color); // copy constructor
    }
}

Vehicle::~Vehicle() {
    if (isValid()) {
        native::DestroyVehicle(id);
    }

    delete data;
    delete color;
    delete damage;
    delete param;
    delete position;
}

/*
 * methods
 * static
 */
Vehicle* Vehicle::create(const VehicleModel& model, const VehiclePosition& position, const VehicleColor& color, const int respawnDelay, const bool siren) {
    vehicleID_t vehicleID = native::CreateVehicle(model.getID(), position.getPosition(), color[Color::COLOR_PRIMARY], color[Color::COLOR_SECONDARY], respawnDelay, siren);

	if (!isValidID(vehicleID)) {
	    format fmt = format("Couldn't create a new vehicle with params: model = %d, position = %s, color = %s, respawnDelay = %d, addSiren = %d")
	            % model.getID() % position.getPosition().toString() % color.print() % respawnDelay % siren;
	    ErrorLog(__FILE__, __LINE__, fmt.str()).print();
	    return nullptr;
	}

	Vehicle* vehicle = new Vehicle(vehicleID, model, position, color, respawnDelay, siren);
	vehicles.insert(pair<vehicleID_t, Vehicle*>(vehicleID, vehicle));

	return vehicles[vehicleID];
}

void Vehicle::destroy(Vehicle* vehicle) {
    if (vehicle->isValid()) {
        vehicles.erase(vehicle->id);
    }

	delete vehicle;
}

Vehicle* Vehicle::get(const vehicleID_t vehicleID) {
    if (!isValid(vehicleID)) {
        return nullptr;
    }

	return vehicles[vehicleID];
}

bool Vehicle::isValid() const {
    return isValid(id);
}

bool Vehicle::isValid(const vehicleID_t vehicleID) {
    bool result = true;

    // check if id is valid
    result &= isValidID(vehicleID);

    // check if there is the vehicle
    result &= isValidVehicle(vehicleID);

    return result;
}

bool Vehicle::isValidID(const vehicleID_t vehicleID) {
	return (vehicleID >= MIN_ID && vehicleID <= MAX_ID);
}

bool Vehicle::isValidVehicle(const vehicleID_t vehicleID) {
    return vehicles.count(vehicleID);
}

/*
 * methods
 * setters & getters
 */
void Vehicle::setID(const vehicleID_t id) {
    if (!isValid(id)) {
        return;
    }

    this->id = id;
}

vehicleID_t Vehicle::getID() const {
    return id;
}

VehicleData* Vehicle::getData() {
    return data;
}

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