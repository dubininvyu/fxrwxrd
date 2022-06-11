//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

class Vehicle;

class VehicleColor {
public:
    enum Color {
        COLOR_PRIMARY,
        COLOR_SECONDARY,

        COUNT
    };
private:
protected:
    Vehicle* vehicle;
    int colors[Color::COUNT];
public:
    VehicleColor(Vehicle* vehicle, const int colors[2]);
    ~VehicleColor();

    bool setupColor();

    void setColor(const Color type, const int color);
    int getColor(const Color type) const;
};