//
// Created by dubininvyu on 21.06.2022.
//

#include "VehicleSignal.h"
#include "Vehicle.h"

VehicleSignal::VehicleSignal() : left(0.0, 0.0, 0.0), right(0.0, 0.0, 0.0) {

}

VehicleSignal::~VehicleSignal() {

}

void VehicleSignal::setLeft(const vec3d& left) {
    this->left = left;
}

vec3d VehicleSignal::getLeft() const {
    return left;
}

void VehicleSignal::setRight(const vec3d& right) {
    this->right = right;
}

vec3d VehicleSignal::getRight() const {
    return right;
}