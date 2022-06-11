//
// Created by dubininvyu on 11.06.2022.
//

#include "VehicleParam.h"
#include "Vehicle.h"

#include "natives.h"
#include "event_handlers.h"

namespace native = api_server::native;

VehicleParam::VehicleParam(Vehicle* vehicle) : vehicle(vehicle) {

}

VehicleParam::~VehicleParam() {

}

bool VehicleParam::setupParams() {
    return native::SetVehicleParamsEx(vehicle->getID(),
            params[PARAM_ENGINE], params[PARAM_LIGHTS], params[PARAM_ALARM], params[PARAM_DOORS],
            params[PARAM_BONNET], params[PARAM_BOOT], params[PARAM_OBJECTIVE]);
}

bool VehicleParam::syncParams() {
    int engine, lights, alarm, doors, bonnet, boot, objective, siren;
    bool result = native::GetVehicleParamsEx(vehicle->getID(),engine, lights, alarm, doors, bonnet, boot, objective);

    params[PARAM_ENGINE] = static_cast<bool>(engine);
    params[PARAM_LIGHTS] = static_cast<bool>(lights);
    params[PARAM_ALARM] = static_cast<bool>(alarm);
    params[PARAM_DOORS] = static_cast<bool>(doors);
    params[PARAM_BONNET] = static_cast<bool>(bonnet);
    params[PARAM_BOOT] = static_cast<bool>(boot);
    params[PARAM_OBJECTIVE] = static_cast<bool>(objective);

    return result;
}

void VehicleParam::setParam(const Param param, const bool value) {
    VehicleParamsUpdateHandler handler(vehicle, param, value);
    bool result = handler.execute();

    if (result) {
        params[param] = value;
        setupParams();
    }
}

bool VehicleParam::getParam(const Param param) const {
    return params[param];
}