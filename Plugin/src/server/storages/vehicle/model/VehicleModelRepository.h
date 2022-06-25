//
// Created by dubininvyu on 21.06.2022.
//


#pragma once

#include "MySQLRepository.h"

class Vehicle;

class VehicleModelRepository : public MySQLRepository {
private:
protected:
    Vehicle* vehicle;
    Mode mode;
public:
    VehicleModelRepository(const Mode mode = MODE_NOPE);
    virtual ~VehicleModelRepository();

    virtual bool preload();

    static unsigned int load();
    virtual unsigned int block();
    virtual unsigned int update();
    virtual unsigned int create();

    /* others */
};

