//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "VehicleEventHandler.h"

class VehicleParamsUpdateHandler : public VehicleEventHandler {
private:
protected:
    VehicleParam::Param param;
    bool newState;
public:
    VehicleParamsUpdateHandler(Vehicle* vehicle, VehicleParam::Param param, bool newState);
    virtual ~VehicleParamsUpdateHandler();

    virtual bool execute();

    bool onEngineStatusUpdate(bool state);
    bool onLightsStatusUpdate(bool state);
    bool onAlarmStatusUpdate(bool state);
    bool onDoorsStatusUpdate(bool state);
    bool onBonnetStatusUpdate(bool state);
    bool onBootStatusUpdate(bool state);
    bool onObjectiveStatusUpdate(bool state);
    bool onSirenStatusUpdate(bool state);
};