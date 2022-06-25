//
// Created by dubininvyu on 20.06.2022.
//


#pragma once

#include <boost/mpl/size_t.hpp>

class Player;
class Vehicle;

typedef size_t transportID_t;

class VehicleData {
private:
protected:
    transportID_t id;
    Vehicle* vehicle;

    Player* owner;
public:
    VehicleData(Vehicle* vehicle);
    ~VehicleData();

    void setID(const transportID_t id);
    transportID_t getID() const;
};

