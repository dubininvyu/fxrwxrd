//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "VehicleEventHandler.h"

#include "Player.h"

class VehicleSirenStateChangeHandler : public VehicleEventHandler {
private:
protected:
    Player* driver;
    bool newState;
public:
    VehicleSirenStateChangeHandler(Vehicle* vehicle, Player* driver, bool newState);
    virtual ~VehicleSirenStateChangeHandler();

    virtual bool execute();
};