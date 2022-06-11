//
// Created by dubininvyu on 11.06.2022.
//

#include "VehicleColor.h"
#include "Vehicle.h"
#include "natives.h"

namespace native = api_server::native;

VehicleColor::VehicleColor(Vehicle* vehicle, const int colors[2]) : vehicle(vehicle), colors{colors[0], colors[1]} {

}

VehicleColor::~VehicleColor() {

}

bool VehicleColor::setupColor() {
    return native::ChangeVehicleColor(vehicle->getID(), colors[COLOR_PRIMARY], colors[COLOR_SECONDARY]);
}

void VehicleColor::setColor(const Color type, const int color) {
    colors[type] = color;
}

int VehicleColor::getColor(const Color type) const {
    return colors[type];
}