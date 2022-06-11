//
// Created by dubininvyu on 11.06.2022.
//

#include "VehicleDamage.h"
#include "Vehicle.h"

#include "natives.h"

namespace native = api_server::native;

VehicleDamage::VehicleDamage(Vehicle* vehicle) : vehicle(vehicle) {

}

VehicleDamage::~VehicleDamage() {

}

bool VehicleDamage::setupDamages() {
    return native::UpdateVehicleDamageStatus(vehicle->getID(),
            damages[DAMAGE_PANELS], damages[DAMAGE_DOORS], damages[DAMAGE_LIGHTS], damages[DAMAGE_TIRES]);
}

bool VehicleDamage::syncDamages() {
    return native::GetVehicleDamageStatus(vehicle->getID(),
            damages[DAMAGE_PANELS], damages[DAMAGE_DOORS], damages[DAMAGE_LIGHTS], damages[DAMAGE_TIRES]);
}

void VehicleDamage::setDamage(const Damage damage, const int value) {
    damages[damage] = value;
    setupDamages();
}

int VehicleDamage::getDamage(const Damage damage) const {
    return damages[damage];
}