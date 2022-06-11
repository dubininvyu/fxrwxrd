//
// Created by dubininvyu on 03.05.2022.
//

#include "VehicleStreamOutHandler.h"

VehicleStreamOutHandler::VehicleStreamOutHandler(Vehicle* vehicle, Player* player) : VehicleEventHandler(vehicle), player(player) {

}

VehicleStreamOutHandler::~VehicleStreamOutHandler() {

}

bool VehicleStreamOutHandler::execute() {

    return true;
}