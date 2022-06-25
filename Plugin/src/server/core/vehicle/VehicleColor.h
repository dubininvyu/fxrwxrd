//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include <string>

using namespace std;

class Vehicle;

typedef unsigned char colorID_t;

class VehicleColor {
public:
    enum Color {
        COLOR_PRIMARY,
        COLOR_SECONDARY,

        colorMax
    };
private:
protected:
    Vehicle* vehicle;

    colorID_t colors[colorMax];
public:
    /*
     * constructors & destructors
     */
    VehicleColor(const colorID_t colors[colorMax]);
    VehicleColor(Vehicle* vehicle, const VehicleColor& color);

    ~VehicleColor();

    /*
     * operators
     */
    colorID_t operator [](const Color colorType) const;

    /*
     * methods
     * checkers
     */
    const bool isValidColor(const Color colorType) const;

    /*
     * methods
     * basic
     */
    string print() const;

    bool setupColor() const;

    /*
     * setters & getters
     */
    void setColor(const Color type, const colorID_t colorType);
    void setColors(const colorID_t colors[colorMax], const bool reWrite = true);
    colorID_t getColor(const Color colorType) const;
};