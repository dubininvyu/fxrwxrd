//
// Created by dubininvyu on 12.06.2022.
//

#include "VehicleDataService.h"
#include "Vehicle.h"
#include "repositories.h"

VehicleDataService::VehicleDataService(Vehicle* vehicle) : VehicleService(vehicle) {

}

VehicleDataService::~VehicleDataService() {

}

unsigned int VehicleDataService::loadVehicles() {
    return VehicleRepository::load();
}