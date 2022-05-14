//
// Created by dubininvyu on 01.05.2022.
//

#include "Vehicle.h"

#include "VehicleParamsUpdateHandler.h"

#include "geometry.h"
#include "natives.h"

namespace native = api_server::native;

Vehicle* Vehicle::vehicles[MAX_COUNT] = {nullptr};

Vehicle::Vehicle(const unsigned int id, const Base& base, const Data& data) : id(id), base(base), data(data) {

}

Vehicle::~Vehicle() {
    if (isValid()) {
        native::DestroyVehicle(id);
    }
}

Vehicle* Vehicle::create(const unsigned int model, const vec4d& pos, const int color[2], const int respawnDelay, const bool siren) {
	unsigned int vehicleID = native::CreateVehicle(model, pos, color[0], color[1], respawnDelay, siren);

	Data data{false, false, false, false, false, false, false, siren};
	Base base{model, pos, {color[0], color[1]}, respawnDelay};

	vehicles[vehicleID] = new Vehicle(vehicleID, base, data);
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

/* vehicle params */

void Vehicle::setParams() {
    native::SetVehicleParamsEx(id, data.engine, data.lights, data.alarm, data.doors, data.bonnet, data.boot, data.objective);
}

void Vehicle::syncParams() {
    int engine, lights, alarm, doors, bonnet, boot, objective, siren = 0;
    native::GetVehicleParamsEx(id, engine, lights, alarm, doors, bonnet, boot, objective);

    data.engine = engine;
    data.lights = lights;
    data.alarm = alarm;
    data.doors = doors;
    data.bonnet = bonnet;
    data.boot = boot;
    data.objective = objective;
    data.siren = siren;
}

void Vehicle::setParam(const Params param, bool value) {

    switch (param) {
        case PARAM_ENGINE:
            this->data.engine = value;
            break;
        case PARAM_LIGHTS:
            this->data.lights = value;
            break;
        case PARAM_ALARM:
            this->data.alarm = value;
            break;
        case PARAM_DOORS:
            this->data.doors = value;
            break;
        case PARAM_BONNET:
            this->data.bonnet = value;
            break;
        case PARAM_BOOT:
            this->data.boot = value;
            break;
        case PARAM_OBJECTIVE:
            this->data.objective = value;
            break;
        case PARAM_SIREN:
            this->data.siren = value;
            break;
    }

    VehicleParamsUpdateHandler handler(*this, param, value);
    bool result = handler.execute();

    if (result) {
        setParams();
    }
}

bool Vehicle::getParam(const Params param) const {
    bool result;

    switch (param) {
        case PARAM_ENGINE:
            result = this->data.engine;
            break;
        case PARAM_LIGHTS:
            result = this->data.lights;
            break;
        case PARAM_ALARM:
            result = this->data.alarm;
            break;
        case PARAM_DOORS:
            result = this->data.doors;
            break;
        case PARAM_BONNET:
            result = this->data.bonnet;
            break;
        case PARAM_BOOT:
            result = this->data.boot;
            break;
        case PARAM_OBJECTIVE:
            result = this->data.objective;
            break;
        case PARAM_SIREN:
            result = this->data.siren;
            break;
    }

    return result;
}

/* vehicle damages */
void Vehicle::setDamages() {
    api_server::native::UpdateVehicleDamageStatus(id, damage.panels, damage.doors, damage.lights, damage.tires);
}

void Vehicle::syncDamages() {
    api_server::native::GetVehicleDamageStatus(id, damage.panels, damage.doors, damage.lights, damage.tires);
}

void Vehicle::setDamage(const Damages damage, bool value) {

    switch (damage) {
        case DAMAGE_PANELS:
            this->damage.panels = value;
            break;
        case DAMAGE_DOORS:
            this->damage.doors = value;
            break;
        case DAMAGE_LIGHTS:
            this->damage.lights = value;
            break;
        case DAMAGE_TIRES:
            this->damage.tires = value;
            break;
    }

    setDamages();
}

bool Vehicle::getDamage(const Damages damage) const {
    bool result;

    switch (damage) {
        case DAMAGE_PANELS:
            result = this->damage.panels;
            break;
        case DAMAGE_DOORS:
            result = this->damage.doors;
            break;
        case DAMAGE_LIGHTS:
            result = this->damage.lights;
            break;
        case DAMAGE_TIRES:
            result = this->damage.tires;
            break;
    }

    return result;
}