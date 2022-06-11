//
// Created by dubininvyu on 03.05.2022.
//

#include "VehiclePaintJobHandler.h"

VehiclePaintJobHandler::VehiclePaintJobHandler(Vehicle* vehicle, int paintJob) : VehicleEventHandler(vehicle), paintJob(paintJob) {

}

VehiclePaintJobHandler::~VehiclePaintJobHandler() {

}

bool VehiclePaintJobHandler::execute() {

    return true;
}