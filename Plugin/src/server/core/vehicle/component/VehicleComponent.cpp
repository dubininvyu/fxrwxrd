//
// Created by dubininvyu on 01.05.2022.
//

#include "VehicleComponent.h"

VehicleComponent::VehicleComponent() : Item() {

}


VehicleComponent::~VehicleComponent() {

}

void VehicleComponent::setMotor(VehicleComponentMotor* motor) {
    this->motor = motor;
}

VehicleComponentMotor* VehicleComponent::getMotor() {
    return motor;
}

void VehicleComponent::setFuelTank(VehicleComponentFuelTank* fuelTank) {
    this->fuelTank = fuelTank;
}

VehicleComponentFuelTank* VehicleComponent::getFuelTank() {
    return fuelTank;
}