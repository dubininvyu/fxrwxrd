//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "VehicleEventHandler.h"

class VehiclePaintJobHandler : public VehicleEventHandler {
private:
protected:
    int paintJob;
public:
    VehiclePaintJobHandler(Vehicle* vehicle, int paintJob);
    virtual ~VehiclePaintJobHandler();

    virtual bool execute();
};