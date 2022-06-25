//
// Created by dubininvyu on 12.06.2022.
//

#include "VehicleModelService.h"
#include "Vehicle.h"
#include "repositories.h"

using namespace std;

VehicleModelService::VehicleModelService() : VehicleService(nullptr) {

}

VehicleModelService::~VehicleModelService() {

}

size_t VehicleModelService::loadModels() {
    return VehicleModelRepository::load();
}