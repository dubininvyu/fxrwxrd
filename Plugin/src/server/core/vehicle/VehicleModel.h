//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "Player.h"
#include "VehicleConfiguration.h"
#include "VehicleSignal.h"

#include <map>
#include <string>

using namespace std;

typedef unsigned int modelID_t;
typedef AccountLicense::License License;

class Vehicle;

class VehicleModel {
public:
    static const unsigned int MIN_ID = 400;
    static const unsigned int MAX_ID = 611;
    static const unsigned int MAX_COUNT = (MAX_ID - MIN_ID);

    enum Info {
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

    enum Type {
        TYPE_NOPE = 0,

        TYPE_CAR,
        TYPE_BOAT,
        TYPE_HELICOPTER,
        TYPE_AIRPLANE,
        TYPE_BICYCLE,
        TYPE_TRAIN,
        TYPE_TRAILER,
        TYPE_BIKE,
        TYPE_REMOTE,
        TYPE_UNKNOWN
    };

private:
protected:
    modelID_t id;
    Vehicle* vehicle;

    Type type;
    License license;

    VehicleSignal* signal;
    VehicleConfiguration* configuration;

    typedef map<modelID_t, VehicleModel*> models_type;
    static models_type models;

    VehicleModel(const modelID_t id, const Type type, const License license);
public:
    /*
     * constructors & destructors
     */
    VehicleModel(const modelID_t id);
    VehicleModel(Vehicle* vehicle, const VehicleModel& vehicleModel); // copy constructor
    ~VehicleModel();

    /*
     * methods
     * static
     */
    static VehicleModel* addModel(const modelID_t id, const Type type, const License license);
    static VehicleModel* getModel(const modelID_t id);

    static bool isValidID(const modelID_t id);
    bool isValidID() const;

    /*
     * methods
     * setters & getters
     */
    void setID(const modelID_t id);
    modelID_t getID() const;

    void setType(const Type type);
    Type getType() const;

    void setLicense(const License license);
    License getLicense() const;

    VehicleSignal* getSignal();
    VehicleConfiguration* getConfiguration();
};
