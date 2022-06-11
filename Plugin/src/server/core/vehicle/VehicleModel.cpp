//
// Created by dubininvyu on 01.05.2022.
//

#include "VehicleModel.h"

VehicleModel::VehicleModel(Vehicle* vehicle, unsigned int model) : vehicle(vehicle), model(model) {

}

VehicleModel::~VehicleModel() {

}

bool VehicleModel::isValid(unsigned int model) {
    return (model >= MIN_ID && model <= MAX_ID);
}

bool VehicleModel::isValid() const {
    return isValid(model);
}