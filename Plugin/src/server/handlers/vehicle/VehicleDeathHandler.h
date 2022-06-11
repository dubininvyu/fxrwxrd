//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "VehicleEventHandler.h"

#include "Player.h"

class VehicleDeathHandler : public VehicleEventHandler {
private:
protected:
    Player* killer;
public:
    VehicleDeathHandler(Vehicle* vehicle, Player* killer = nullptr);
    virtual ~VehicleDeathHandler();

    virtual bool execute();
};