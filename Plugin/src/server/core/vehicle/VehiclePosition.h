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
    VehiclePosition(Vehicle* vehicle, const vec4d& position);
    ~VehiclePosition();

    bool setupPosition();
    bool syncPosition();

    void setPosition(const vec4d& position);
    vec4d getPosition() const;
};

