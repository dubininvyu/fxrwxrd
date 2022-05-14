//
// Created by dubininvyu on 03.05.2022.
//

#include "VehicleDamageHandler.h"

VehicleDamageHandler::VehicleDamageHandler(Vehicle& vehicle, Player* damager) : VehicleEventHandler(vehicle), damager(damager) {

}

VehicleDamageHandler::~VehicleDamageHandler() {

}

bool VehicleDamageHandler::execute() {

    return true;
}