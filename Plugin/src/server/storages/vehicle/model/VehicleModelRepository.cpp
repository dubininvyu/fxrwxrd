//
// Created by dubininvyu on 21.06.2022.
//

#include "VehicleModelRepository.h"
#include "VehicleModel.h"
#include "InfoLog.h"

#include "databases.h"
#include "boost/format.hpp"

using namespace boost;

typedef VehicleModel::Type ModelType;
typedef AccountLicense::License License;

VehicleModelRepository::VehicleModelRepository(const Mode mode) : MySQLRepository(mode) {

}

VehicleModelRepository::~VehicleModelRepository() {

}

bool VehicleModelRepository::preload() {
    return true;
}

unsigned int VehicleModelRepository::load() {
    string query = "SELECT * FROM `vehicles_models`";

    MySQLConnector connector(MainDatabase::getInstance());
    connector.query(query);

    SQLResult result = connector.storeResult();

    if (!result) {
        return 0;
    }

    size_t rows = result.getNumRows();

    if (!rows) {
        return 0;
    }

    for (size_t i = 0; i < rows; i++) {
        MYSQL_ROW row = result.fetchRow();

        enum {
            ID, NAME, TYPE, LICENSE, SPEED, FUEL_MAX, FUEL_CHG,
            SIGNAL_LX, SIGNAL_LY, SIGNAL_LZ, SIGNAL_RX, SIGNAL_RY, SIGNAL_RZ,
        };

        modelID_t model = atoi(row[ID]);
        ModelType type = static_cast<ModelType>(atoi(row[TYPE]));
        License license = static_cast<License>(atoi(row[LICENSE]));

        VehicleModel* vehicleModel = VehicleModel::addModel(model, type, license);

        // set engine
        // ...
        // set fuel tank
        // ...

        // set signals
        /*vec3d left(atof(row[SIGNAL_LX]), atof(row[SIGNAL_LY]), atof(row[SIGNAL_LZ]));
        vec3d right(atof(row[SIGNAL_RX]), atof(row[SIGNAL_RY]), atof(row[SIGNAL_RZ]));

        vehicleModel->getSignal()->setLeft(left);
        vehicleModel->getSignal()->setRight(right);*/
    }

    return rows;
}

unsigned int VehicleModelRepository::block() {
    return 0;
}

unsigned int VehicleModelRepository::update() {
    return 0;
}

unsigned int VehicleModelRepository::create() {
    return 0;
}
