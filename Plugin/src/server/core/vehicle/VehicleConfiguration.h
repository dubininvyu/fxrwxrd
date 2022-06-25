//
// Created by dubininvyu on 12.06.2022.
//


#pragma once

#include "components.h"

class Vehicle;

class VehicleConfiguration {
public:
private:
protected:
    Vehicle* vehicle;

    VehicleComponentMotor* motor;
public:
    VehicleConfiguration();
    VehicleConfiguration(Vehicle* vehicle, const VehicleConfiguration& vehicleInfo);
    virtual ~VehicleConfiguration();

    VehicleComponentMotor* getMotor();
};

