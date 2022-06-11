//
// Created by dubininvyu on 12.06.2022.
//

#pragma once

#include "VehicleService.h"

class Vehicle;

class VehicleDataService : public VehicleService {
private:
protected:
public:
    VehicleDataService(Vehicle* vehicle);
    ~VehicleDataService();

    static unsigned int loadVehicles();
};

