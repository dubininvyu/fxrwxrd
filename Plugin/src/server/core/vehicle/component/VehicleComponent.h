//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include "Item.h"

class VehicleComponentMotor;
class VehicleComponentFuelTank;

class Vehicle;

class VehicleComponent : Item {
public:
    enum ComponentType {
        SPOILER = 0,
        HOOD,
        ROOF,
        SIDE_SKIRT,
        LAMPS,
        NITRO,
        EXHAUST,
        WHEELS,
        STEREO,
        HYDRAULICS,
        BUMPER_FRONT,
        BUMPER_REAR,
        VENT_RIGHT,
        VENT_LEFT
    };
private:
protected:
    Vehicle* vehicle;

    VehicleComponentMotor* motor;
    VehicleComponentFuelTank* fuelTank;
public:
    VehicleComponent();
    virtual ~VehicleComponent();

    void setMotor(VehicleComponentMotor* motor);
    VehicleComponentMotor* getMotor();

    void setFuelTank(VehicleComponentFuelTank* fuelTank);
    VehicleComponentFuelTank* getFuelTank();
};

