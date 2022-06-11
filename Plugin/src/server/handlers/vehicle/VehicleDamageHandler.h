//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "VehicleEventHandler.h"

#include "Player.h"

class VehicleDamageHandler : public VehicleEventHandler {
private:
protected:
    Player* damager;
public:
    VehicleDamageHandler(Vehicle* vehicle, Player* damager = nullptr);
    virtual ~VehicleDamageHandler();

    virtual bool execute();
};