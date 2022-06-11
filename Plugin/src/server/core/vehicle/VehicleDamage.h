//
// Created by dubininvyu on 11.06.2022.
//

#pragma once

class Vehicle;

class VehicleDamage {
public:
    enum Damage {
        DAMAGE_PANELS = 0,
        DAMAGE_DOORS,
        DAMAGE_LIGHTS,
        DAMAGE_TIRES,

        COUNT
    };
private:
protected:
    Vehicle* vehicle;
    int damages[Damage::COUNT];
public:
    VehicleDamage(Vehicle* vehicle);
    ~VehicleDamage();

    bool setupDamages();
    bool syncDamages();

    void setDamage(const Damage damage, const int value);
    int getDamage(const Damage damage) const;
};