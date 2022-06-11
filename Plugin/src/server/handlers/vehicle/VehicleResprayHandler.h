//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "VehicleEventHandler.h"

class VehicleResprayHandler : public VehicleEventHandler {
private:
protected:
    int color[2];
public:
    VehicleResprayHandler(Vehicle& vehicle, int color1, int color2);
    virtual ~VehicleResprayHandler();

    virtual bool execute();
};