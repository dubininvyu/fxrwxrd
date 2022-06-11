//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Service.h"

class Vehicle;

class VehicleService : public Service {
private:
protected:
    Vehicle* vehicle;

    unsigned int stage;

    VehicleService(Vehicle* vehicle);
public:
    virtual ~VehicleService() = 0;
};

