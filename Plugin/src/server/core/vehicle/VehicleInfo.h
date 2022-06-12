//
// Created by dubininvyu on 12.06.2022.
//


#pragma once

#include "components.h"

class Vehicle;

class VehicleInfo {
public:
private:
protected:
    VehicleComponentMotor* motor;
public:
    VehicleInfo();
    virtual ~VehicleInfo();

    VehicleComponentMotor* getMotor();
};

