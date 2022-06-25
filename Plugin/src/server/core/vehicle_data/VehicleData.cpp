//
// Created by dubininvyu on 20.06.2022.
//

#include "VehicleData.h"

VehicleData::VehicleData(Vehicle* vehicle) : vehicle(vehicle) {

}

VehicleData::~VehicleData() {

}

void VehicleData::setID(const transportID_t id) {
    this->id = id;
}

transportID_t VehicleData::getID() const {
    return id;
}