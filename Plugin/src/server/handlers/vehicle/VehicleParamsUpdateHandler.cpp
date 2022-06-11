//
// Created by dubininvyu on 03.05.2022.
//

#include "VehicleParamsUpdateHandler.h"

VehicleParamsUpdateHandler::VehicleParamsUpdateHandler(Vehicle& vehicle, Vehicle::Params param, bool newState) :
    VehicleEventHandler(vehicle), param(param), newState(newState) {

}

VehicleParamsUpdateHandler::~VehicleParamsUpdateHandler() {

}

bool VehicleParamsUpdateHandler::execute() {

    if (param == Vehicle::PARAM_ENGINE) {
        return onEngineStatusUpdate(newState);
    }

    if (param == Vehicle::PARAM_LIGHTS) {
        return onLightsStatusUpdate(newState);
    }

    if (param == Vehicle::PARAM_ALARM) {
        return onAlarmStatusUpdate(newState);
    }

    if (param == Vehicle::PARAM_DOORS) {
        return onDoorsStatusUpdate(newState);
    }

    if (param == Vehicle::PARAM_BONNET) {
        return onBonnetStatusUpdate(newState);
    }

    if (param == Vehicle::PARAM_BOOT) {
        return onBootStatusUpdate(newState);
    }

    if (param == Vehicle::PARAM_OBJECTIVE) {
        return onObjectiveStatusUpdate(newState);
    }

    if (param == Vehicle::PARAM_SIREN) {
        return onSirenStatusUpdate(newState);
    }

    return true;
}

bool VehicleParamsUpdateHandler::onEngineStatusUpdate(bool state) {
    return true;
}

bool VehicleParamsUpdateHandler::onLightsStatusUpdate(bool state) {
    return true;
}

bool VehicleParamsUpdateHandler::onAlarmStatusUpdate(bool state) {
    return true;
}

bool VehicleParamsUpdateHandler::onDoorsStatusUpdate(bool state) {
    return true;
}

bool VehicleParamsUpdateHandler::onBonnetStatusUpdate(bool state) {
    return true;
}

bool VehicleParamsUpdateHandler::onBootStatusUpdate(bool state) {
    return true;
}

bool VehicleParamsUpdateHandler::onObjectiveStatusUpdate(bool state) {
    return true;
}

bool VehicleParamsUpdateHandler::onSirenStatusUpdate(bool state) {
    return true;
}