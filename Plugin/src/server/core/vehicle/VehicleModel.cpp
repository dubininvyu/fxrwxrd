//
// Created by dubininvyu on 01.05.2022.
//

#include "VehicleModel.h"

#include "logs.h"

#include "boost/format.hpp"

using namespace std;
using namespace boost;

VehicleModel::models_type VehicleModel::models;

/*
 * constructors & destructors
 * protected constructor
 */
VehicleModel::VehicleModel(const modelID_t id, const Type type, const AccountLicense::License license) :
    id(id), type(type), license(license) {

    signal = new VehicleSignal();
    configuration = new VehicleConfiguration();
}

/*
 * constructors & destructors
 * public constructor for static vehicles models
 */
VehicleModel::VehicleModel(const modelID_t id) : id(id) {
    if (!isValidID(id)) {
        format fmt = format("Couldn't use a vehicle model #%d: invalid ID") % id;
        ErrorLog(__FILE__, __LINE__, fmt.str()).print();
    }

    VehicleModel* model = getModel(id);

    if (!model) { // model == nullptr
        format fmt = format("Couldn't use a vehicle model #%d: invalid pointer") % id;
        ErrorLog(__FILE__, __LINE__, fmt.str()).print();

        return;
    }

    type = model->type;
    license = model->license;

    signal = nullptr;
    configuration = nullptr;
}

VehicleModel::VehicleModel(Vehicle* vehicle, const VehicleModel& vehicleModel) : vehicle(vehicle),
    id(vehicleModel.id), type(vehicleModel.type), license(vehicleModel.license) {

    configuration = new VehicleConfiguration(vehicle, *vehicleModel.configuration);
}

VehicleModel::~VehicleModel() {
    delete signal;
    delete configuration;
}

/*
 * methods
 * static
 */
VehicleModel* VehicleModel::addModel(const modelID_t id, const Type type, const AccountLicense::License license) {
    VehicleModel* vehicleModel = new VehicleModel(id, type, license);
    models.insert(pair<modelID_t, VehicleModel*>(id, vehicleModel));
    return vehicleModel;
}

VehicleModel* VehicleModel::getModel(const modelID_t id) {
    if (!isValidID(id)) {
        return nullptr;
    }

    if (!models.count(id)) {
        return nullptr;
    }

    return models.at(id);
}

bool VehicleModel::isValidID(const modelID_t id) {
    return (id >= MIN_ID && id <= MAX_ID);
}

bool VehicleModel::isValidID() const {
    return isValidID(id);
}

/*
 * methods
 * setters & getters
 */
void VehicleModel::setID(const modelID_t id) {
    this->id = id;
}

modelID_t VehicleModel::getID() const {
    return id;
}

void VehicleModel::setType(const Type type) {
    this->type = type;
}

VehicleModel::Type VehicleModel::getType() const {
    return type;
}

void VehicleModel::setLicense(const License license) {
    this->license = license;
}

License VehicleModel::getLicense() const {
    return license;
}

VehicleConfiguration* VehicleModel::getConfiguration() {
    return configuration;
}

VehicleSignal* VehicleModel::getSignal() {
    return signal;
}