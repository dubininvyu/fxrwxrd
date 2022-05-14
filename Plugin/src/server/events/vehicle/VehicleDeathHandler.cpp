//
// Created by dubininvyu on 03.05.2022.
//

#include "VehicleDeathHandler.h"

VehicleDeathHandler::VehicleDeathHandler(Vehicle& vehicle, Player* killer) : VehicleEventHandler(vehicle), killer(killer) {

}

VehicleDeathHandler::~VehicleDeathHandler() {

}

bool VehicleDeathHandler::execute() {

    return true;
}