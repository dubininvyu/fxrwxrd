//
// Created by dubininvyu on 03.05.2022.
//

#include "VehicleStreamInHandler.h"

VehicleStreamInHandler::VehicleStreamInHandler(Vehicle* vehicle, Player* player) : VehicleEventHandler(vehicle), player(player) {

}

VehicleStreamInHandler::~VehicleStreamInHandler() {

}

bool VehicleStreamInHandler::execute() {

    return true;
}