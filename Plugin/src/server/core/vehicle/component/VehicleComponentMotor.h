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
    virtual ~VehicleComponentMotor();

    virtual float getFuelConsumption() = 0;

    virtual float getMinSpeed();
    virtual float getMaxSpeed() = 0;
};

