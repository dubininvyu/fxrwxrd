//
// Created by dubininvyu on 12.06.2022.
//


#pragma once

#include "VehicleComponent.h"

class VehicleComponentMotor : public VehicleComponent {
private:
protected:
public:
    VehicleComponentMotor();
    ~VehicleComponentMotor();

    virtual unsigned int getFuelConsumption() = 0;

    virtual unsigned int getMinSpeed() = 0;
    virtual unsigned int getMaxSpeed() = 0;
};

