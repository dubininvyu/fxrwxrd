//
// Created by dubininvyu on 12.06.2022.
//

#include "VehicleRepository.h"
#include "Vehicle.h"
#include "MainDatabase.h"
#include "ErrorLog.h"
#include "geometry.h"

#include "boost/format.hpp"
#include "json-parser/json.hpp"

using namespace std;
using namespace boost;
using namespace geometry;

using json = nlohmann::json;

VehicleRepository::VehicleRepository(Vehicle* vehicle, const Mode mode) : MySQLRepository(), vehicle(vehicle), mode(mode) {
    if (mode & MODE_READ_ALL) {
        preload();
    }
}

VehicleRepository::~VehicleRepository() {

}

bool VehicleRepository::preload() {
    return true;
}

unsigned int VehicleRepository::load() {
    MySQLConnector connector(MainDatabase::getInstance());
    connector.query("SELECT * FROM `vehicles` AS v LEFT JOIN `vehicles_positions` AS vp ON v.`id` = vp.`vehicle`");

    SQLResult result = connector.storeResult();
    if (!result) {
        return 0;
    }

    const size_t rows = result.getNumRows();
    if (!rows) {
        return 0;
    }

    enum {
        // vehicles
        ID, MODEL, COLOR, SIREN,
        // vehicles_positions
        ID_, VEHICLE, COORD_X, COORD_Y, COORD_Z, COORD_A,
    };

    for (int i = 0; i < rows; i++) {
        MYSQL_ROW row = result.fetchRow();

        vec4d position (
                atof(row[COORD_X]),
                atof(row[COORD_X]),
                atof(row[COORD_X]),
                atof(row[COORD_X])
        );

        unsigned int model = atoi(row[MODEL]);
        bool siren = atoi(row[SIREN]);

        json json = json::parse(row[COLOR]);
        int colors[2] {json["color"]["main"][0], json["color"]["main"][1]};

        Vehicle* vehicle = Vehicle::create(model, position, colors, -1, siren);

        if (!vehicle) {
            ErrorLog(__FILE__, __LINE__, "Error loading vehicles").print();
            break;
        }

        // components, damages, ...
    }

    return rows;
}

unsigned int VehicleRepository::block() {
    return 0;
}

unsigned int VehicleRepository::update() {
    return 0;
}

unsigned int VehicleRepository::create() {
    return 0;
}