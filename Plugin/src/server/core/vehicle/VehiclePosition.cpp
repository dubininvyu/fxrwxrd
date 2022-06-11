//
// Created by dubininvyu on 11.06.2022.
//

#include "VehiclePosition.h"
#include "Vehicle.h"
#include "natives.h"

namespace native = api_server::native;
using namespace geometry;

VehiclePosition::VehiclePosition(Vehicle* vehicle, const vec4d& position) : vehicle(vehicle), vec4d(position) {

}

VehiclePosition::~VehiclePosition() {

}

bool VehiclePosition::setupPosition() {
    bool result = true;

    result &= native::SetVehiclePos(vehicle->getID(), {x, y, z});
    result &= native::SetVehicleZAngle(vehicle->getID(), a);

    return result;
}

bool VehiclePosition::syncPosition() {
    bool result = true;

    vec3d position{};

    result &= native::GetVehiclePos(vehicle->getID(), position);
    result &= native::GetVehicleZAngle(vehicle->getID(), a);

    x = position.getX();
    y = position.getY();
    z = position.getZ();

    return result;
}

void VehiclePosition::setPosition(const vec4d& position) {
    x = position.getX();
    y = position.getY();
    z = position.getZ();
    a = position.getA();
}

vec4d VehiclePosition::getPosition() const {
    return {x, y, z, a};
}