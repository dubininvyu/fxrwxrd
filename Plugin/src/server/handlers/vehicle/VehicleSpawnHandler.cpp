//
// Created by dubininvyu on 03.05.2022.
//

#include "VehicleSpawnHandler.h"

VehicleSpawnHandler::VehicleSpawnHandler(Vehicle& vehicle) : VehicleEventHandler(vehicle) {

}

VehicleSpawnHandler::~VehicleSpawnHandler() {

}

bool VehicleSpawnHandler::execute() {

    return true;
}