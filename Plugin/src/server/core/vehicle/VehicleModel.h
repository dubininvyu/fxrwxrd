//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

class Vehicle;

class VehicleModel {
public:
    static const unsigned int MIN_ID = 400;
    static const unsigned int MAX_ID = 611;
    static const unsigned int MAX_COUNT = (MAX_ID - MIN_ID);

    enum ModelInfo {
        SIZE = 1,
        FRONT_SEAT,
        REAR_SEAT,
        PETROL_CAP,
        WHEELS_FRONT,
        WHEELS_REAR,
        WHEELS_MIDDLE,
        BUMPER_Z_FRONT,
        BUMPER_Z_REAR
    };
private:
protected:
    Vehicle* vehicle;
    unsigned int model;
public:
    VehicleModel(Vehicle* vehicle, unsigned int model);
    ~VehicleModel();

    static bool isValid(unsigned int model);
    bool isValid() const;
};
