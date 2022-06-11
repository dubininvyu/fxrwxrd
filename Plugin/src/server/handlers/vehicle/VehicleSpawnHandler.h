//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "VehicleEventHandler.h"

class VehicleSpawnHandler : public VehicleEventHandler {
private:
protected:
public:
    VehicleSpawnHandler(Vehicle& vehicle);
    virtual ~VehicleSpawnHandler();

    virtual bool execute();
};