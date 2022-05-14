//
// Created by dubininvyu on 03.05.2022.
//

#include "VehicleResprayHandler.h"

VehicleResprayHandler::VehicleResprayHandler(Vehicle& vehicle, int color1, int color2) :
    VehicleEventHandler(vehicle), color{color1, color2} {

}

VehicleResprayHandler::~VehicleResprayHandler() {

}

bool VehicleResprayHandler::execute() {

    return true;
}