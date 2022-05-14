//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "Vehicle.h"
#include "EventHandler.h"

class VehicleEventHandler : public EventHandler {
private:
protected:
    Vehicle& vehicle;
    VehicleEventHandler(Vehicle& vehicle);
public:
    virtual ~VehicleEventHandler() = 0;
};

