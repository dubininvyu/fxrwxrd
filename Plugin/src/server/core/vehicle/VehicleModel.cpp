//
// Created by dubininvyu on 01.05.2022.
//

#include "VehicleModel.h"

VehicleModel::VehicleModel(Vehicle* vehicle, unsigned int model) : vehicle(vehicle), model(model) {

}

VehicleModel::VehicleModel(const unsigned int model, const string& name, const PlayerLicense::License license) :
    model(model), name(name), license(license) {

}

VehicleModel::~VehicleModel() {

}

bool VehicleModel::isValid(unsigned int model) {
    return (model >= MIN_ID && model <= MAX_ID);
}

bool VehicleModel::isValid() const {
    return isValid(model);
}

ModelType* VehicleModel::getType() {
    return type;
}

void VehicleModel::setInfo(VehicleInfo* info) {
    this->info = info;
}

VehicleInfo* VehicleModel::getInfo() {
    return info;
}