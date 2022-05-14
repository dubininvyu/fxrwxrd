//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "Dialog.h"

#include <string>
#include <map>

using namespace std;

class Color {
public:
    enum e_COLORS {
        COLOR_BLACK = 0x000000,
        COLOR_WHITE = 0xFFFFFF
    };
private:
protected:
	int color;
public:
    Color();
    Color(const int color);
    ~Color();

    /* operators */
    operator int() const;
    operator string() const;

    /* functions */
    int toXX() const;
    string toString() const;

    static int toXX(const int color);
    static string toString(const int color);

    /* setters & getters */
    void setColor(const int color);
    int getColor() const;
};