//
// Created by dubininvyu on 12.06.2022.
//

#pragma once

#include "MySQLRepository.h"

class Vehicle;

class VehicleRepository : public MySQLRepository {
private:
protected:
    Vehicle* vehicle;
    Mode mode;
public:
    VehicleRepository(Vehicle* vehicle, const Mode mode = MODE_NOPE);
    virtual ~VehicleRepository();

    virtual bool preload();

    static unsigned int loadVehicles();
    //unsigned int createAccount(const string& password, PersonSex::Sex sex);
};

