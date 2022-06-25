//
// Created by dubininvyu on 11.06.2022.
//

#include "VehicleColor.h"
#include "Vehicle.h"
#include "Exception.h"

#include "logs.h"
#include "natives.h"

#include "boost/format.hpp"

using namespace std;
using namespace boost;

namespace native = api_server::native;

/*
 * constructors & destructors
 */
VehicleColor::VehicleColor(const colorID_t colors[colorMax]) : vehicle(nullptr), colors{colors[COLOR_PRIMARY], colors[COLOR_SECONDARY]} {

}

VehicleColor::VehicleColor(Vehicle* vehicle, const VehicleColor& color) :
    vehicle(vehicle), colors{color.colors[COLOR_PRIMARY], color.colors[COLOR_SECONDARY]} {

}

VehicleColor::~VehicleColor() {

}

/*
 * operators
 */
colorID_t VehicleColor::operator [](const Color colorType) const {
    return getColor(colorType);
}

/*
 * methods
 * checkers
 */
const bool VehicleColor::isValidColor(const Color colorType) const {
    return (colorType >= COLOR_PRIMARY && colorType < colorMax);
}

/*
 * methods
 * basic
 */
string VehicleColor::print() const {
    format fmt = format("color1 = %d, color2 = %d") % colors[COLOR_PRIMARY] % colors[COLOR_SECONDARY];
    return fmt.str();
}

bool VehicleColor::setupColor() const {
    return native::ChangeVehicleColor(vehicle->getID(), colors[COLOR_PRIMARY], colors[COLOR_SECONDARY]);
}

/*
 * setters & getters
 */

void VehicleColor::setColor(const Color colorType, const colorID_t color) {
    colors[colorType] = color;
}

void VehicleColor::setColors(const colorID_t colors[colorMax], const bool reWrite) {
    this->colors[COLOR_PRIMARY] = colors[COLOR_PRIMARY];
    this->colors[COLOR_SECONDARY] = colors[COLOR_SECONDARY];

    setupColor(); // setup changes

    if (reWrite) {
        // saving changes
    }
}

colorID_t VehicleColor::getColor(const Color colorType) const {
    if (!isValidColor(colorType)) {
        try {
            format fmt = format("Invalid color type #%d") % colorType;
            throw Exception(__FILE__, __LINE__, fmt.str());
        }
        catch(const Exception& exception) {
            exception.print();
        }
    }

    return colors[colorType];
}