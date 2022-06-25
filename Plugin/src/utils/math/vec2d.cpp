//
// Created by dubininvyu on 01.05.2022.
//

#include "geometry.h"
#include "boost/format.hpp"
#include <cmath>

using namespace std;
using namespace boost;
using namespace geometry;

/*
 * constructors & destructors
 */
vec2d::vec2d() : x(0.0), y(0.0) {

}

vec2d::vec2d(const float x, const float y) : x(x), y(y) {

}

vec2d::vec2d(const vec2d& v) : x(v.x), y(v.y) {

}

/*
 * operators
 */
vec2d vec2d::operator-(const vec2d& v) const {
	return vec2d(this->x-v.x, this->y-v.y);
}

vec2d vec2d::operator+(const vec2d& v) const {
	return vec2d(this->x+v.x, this->y+v.y);
}

vec2d vec2d::operator*(const float value) const {
	return vec2d(this->x*value, this->y*value);
}

vec2d vec2d::operator*(const vec2d& v) const {
	return vec2d(this->x*v.x, this->y*v.y);
}

vec2d vec2d::operator/(const float value) const {
	return vec2d(this->x/value, this->y/value);
}

vec2d vec2d::operator/(const vec2d& v) const {
	return vec2d(this->x/v.x, this->y/v.y);
}

bool vec2d::operator==(const vec2d& v) const {
	return (this->x == v.x && this->y == v.y);
}

bool vec2d::operator!=(const vec2d& v) const {
	return !(*this == v);
}

/*
 * methods
 */
string vec2d::toString() const {
    format fmt = format("x = %f, y = %f") % x % y;
    return fmt.str();
}

float vec2d::distance(const vec2d& v) const {
	return (*this - v).length();
}

float vec2d::length() const {
	return sqrt((x * x) + (y * y));
}

void vec2d::move(const float distance, const float rotateRadian) {
	x += distance* cos(rotateRadian);
	y += distance* sin(rotateRadian);
}

vec2d vec2d::move2d(const float distance, const float rotateRadian) const {
	return vec2d(x + distance* cos(rotateRadian), y + distance* sin(rotateRadian));
}

/*
 * setters & getters
 */
void vec2d::setX(const float x) {
	this->x = x;
}

float vec2d::getX() const {
	return this->x;
}

void vec2d::setY(const float y) {
	this->y = y;
}

float vec2d::getY() const {
	return this->y;
}