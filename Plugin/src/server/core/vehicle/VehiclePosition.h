//
// Created by dubininvyu on 11.06.2022.
//

#pragma once

#include "geometry.h"

class Vehicle;

using namespace geometry;

class VehiclePosition : public vec4d {
public:
private:
protected:
    Vehicle* vehicle;
public:
    /*
     * constructors & destructors
     */
    VehiclePosition(const vec4d& position);
    VehiclePosition(Vehicle* vehicle, const vec4d& position);

    ~VehiclePosition();

    /*
     * methods
     */
    bool setupPosition() const;
    bool syncPosition();

    /*
     * setters & getters
     */
    void setPosition(const vec4d& position);
    vec4d getPosition() const;
};

