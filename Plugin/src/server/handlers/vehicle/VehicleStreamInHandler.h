//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "VehicleEventHandler.h"

#include "Player.h"

class VehicleStreamInHandler : public VehicleEventHandler {
private:
protected:
    Player* player;
public:
    VehicleStreamInHandler(Vehicle& vehicle, Player* player = nullptr);
    virtual ~VehicleStreamInHandler();

    virtual bool execute();
};