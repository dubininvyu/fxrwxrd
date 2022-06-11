//
// Created by dubininvyu on 11.06.2022.
//


#pragma once

class Vehicle;

class VehicleParam {
public:
    enum Param {
        PARAM_ENGINE = 0,
        PARAM_LIGHTS,
        PARAM_ALARM,
        PARAM_DOORS,
        PARAM_BONNET,
        PARAM_BOOT,
        PARAM_OBJECTIVE,
        PARAM_SIREN,

        COUNT
    };
private:
protected:
    Vehicle* vehicle;
    bool params[Param::COUNT];
public:
    VehicleParam(Vehicle* vehicle);
    ~VehicleParam();

    bool setupParams();
    bool syncParams();

    void setParam(const Param param, const bool value);
    bool getParam(const Param param) const;
};

