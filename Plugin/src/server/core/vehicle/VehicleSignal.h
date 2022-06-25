//
// Created by dubininvyu on 21.06.2022.
//


#pragma once

#include "geometry.h"

using namespace geometry;

class Vehicle;

class VehicleSignal {
private:
protected:
    vec3d left;
    vec3d right;
public:
    VehicleSignal();
    ~VehicleSignal();

    void setLeft(const vec3d& left);
    vec3d getLeft() const;

    void setRight(const vec3d& right);
    vec3d getRight() const;
};

