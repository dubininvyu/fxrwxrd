//
// Created by dubininvyu on 03.05.2022.
//

#include "VehicleSirenStateChangeHandler.h"

VehicleSirenStateChangeHandler::VehicleSirenStateChangeHandler(Vehicle& vehicle, Player* driver, bool newState) :
    VehicleEventHandler(vehicle), driver(driver), newState(newState) {

}

VehicleSirenStateChangeHandler::~VehicleSirenStateChangeHandler() {

}

bool VehicleSirenStateChangeHandler::execute() {

    return true;
}