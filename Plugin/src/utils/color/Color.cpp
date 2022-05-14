//
// Created by dubininvyu on 01.05.2022.
//

#include "Color.h"

#include <string>
#include <sstream>

using namespace std;

Color::Color() : color(0) {

}

Color::Color(const int color) : color(color) {

}

Color::~Color() {

}

/* operators */
Color::operator int() const {
    return color;
}

Color::operator string() const {
    return toString();
}

/* functions */
int Color::toXX() const {
    return Color::toXX(color);
}

string Color::toString() const {
    return Color::toString(color);
}

int Color::toXX(const int color) {
    return color * 0xFF;
}

string Color::toString(const int color) {
    stringstream ss;
    ss << '{' << hex << int(color) << '}';
    return ss.str();
}

/* setters & getters */
void Color::setColor(const int color) {
    this->color = color;
}

int Color::getColor() const {
    return color;
}