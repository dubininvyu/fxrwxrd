//
// Created by dubininvyu on 12.06.2022.
//

#include "VehicleConfiguration.h"

VehicleConfiguration::VehicleConfiguration() {
    //motor = new VehicleComponentMotor();
}

VehicleConfiguration::VehicleConfiguration(Vehicle* vehicle, const VehicleConfiguration& vehicleInfo) : vehicle(vehicle),
                                                                                                        motor(vehicleInfo.motor) {

}

VehicleConfiguration::~VehicleConfiguration() {
    //delete motor;
}

VehicleComponentMotor* VehicleConfiguration::getMotor() {
    return motor;
}