//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "VehicleEventHandler.h"

#include "Player.h"

class VehicleStreamOutHandler : public VehicleEventHandler {
private:
protected:
    Player* player;
public:
    VehicleStreamOutHandler(Vehicle& vehicle, Player* player = nullptr);
    virtual ~VehicleStreamOutHandler();

    virtual bool execute();
};