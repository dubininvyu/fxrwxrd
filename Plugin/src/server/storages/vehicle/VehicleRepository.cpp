//
// Created by dubininvyu on 12.06.2022.
//

#include "VehicleRepository.h"
#include "Vehicle.h"
#include "MainDatabase.h"
#include "geometry.h"

#include "logs.h"

#include "boost/format.hpp"
#include "json-parser/json.hpp"

using namespace std;
using namespace boost;
using namespace geometry;

using json = nlohmann::json;

typedef VehicleColor::Color Color;

VehicleRepository::VehicleRepository(Vehicle* vehicle, const Mode mode) : MySQLRepository(mode), vehicle(vehicle) {

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

        vec4d position(
                atof(row[COORD_X]),
                atof(row[COORD_Y]),
                atof(row[COORD_Z]),
                atof(row[COORD_A])
        );

        modelID_t model = atoi(row[MODEL]);
        bool siren = atoi(row[SIREN]);
        colorID_t colors[VehicleColor::colorMax];

        try {
            json json = json::parse(row[COLOR]);
            colors[Color::COLOR_PRIMARY] = json["main"][Color::COLOR_PRIMARY];
            colors[Color::COLOR_SECONDARY] = json["main"][Color::COLOR_SECONDARY];
        }
        catch (const json::exception& exception) {
            string message = "Couldn't parse vehicle color: " + string(exception.what());
            ErrorLog(__FILE__, __LINE__, message).print();
        }

        Vehicle* vehicle = Vehicle::create(model, position, colors, -1, true);

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