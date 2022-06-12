//
// Created by dubininvyu on 12.06.2022.
//

#include "VehicleInfo.h"

VehicleInfo::VehicleInfo() {
    //motor = new VehicleComponentMotor();
}

VehicleInfo::~VehicleInfo() {
    //delete motor;
}

VehicleComponentMotor* VehicleInfo::getMotor() {
    return motor;
}