//
// Created by dubininvyu on 12.06.2022.
//

#pragma once

#include "VehicleService.h"
#include "VehicleModel.h"

class Vehicle;

class VehicleModelService : public VehicleService {
private:
protected:
public:
    VehicleModelService();
    ~VehicleModelService();

    static size_t loadModels();
};