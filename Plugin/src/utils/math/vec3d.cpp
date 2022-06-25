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
vec3d::vec3d() : vec2d(0.0, 0.0), z(0.0) {

}

vec3d::vec3d(const float x, const float y, const float z) : vec2d(x,y), z(z) {

}

vec3d::vec3d(const vec2d& v, const float z) : vec2d(v), z(z) {

}

vec3d::vec3d(const vec3d& v) : vec2d(v.x, v.y), z(v.z) {

}

/*
 * operators
 */
vec3d vec3d::operator-(const vec3d& v) const {
	return vec3d(this->x-v.getX(), this->y-v.getY(), this->z-v.getZ());
}

vec3d vec3d::operator+(const vec3d& v) const {
	return vec3d(this->x+v.getX(), this->y+v.getY(), this->z-v.getZ());
}

vec3d vec3d::operator*(const float value) const {
	return vec3d(this->x*value, this->y*value, this->z*value);
}

vec3d vec3d::operator*(const vec3d& v) const {
	return vec3d(this->x*v.getX(), this->getY(), this->z*v.getZ());
}

vec3d vec3d::operator/(const float value) const {
	return vec3d(this->x/value, this->y/value, this->z/value);
}

vec3d vec3d::operator/(const vec3d& v) const {
	return vec3d(this->x/v.getX(), this->y/v.getY(), this->z/v.getZ());
}

bool vec3d::operator==(const vec3d& v) const {
	return (this->x == v.getX() && this->y == v.getY() && this->z == v.getZ());
}

bool vec3d::operator!=(const vec3d& v) const {
	return !(*this == v);
}

/*
 * methods
 */
string vec3d::toString() const {
    format fmt = format("%s, z = %f") % vec2d::toString() % z;
    return fmt.str();
}

float vec3d::distance(const vec3d& v) const {
	return (*this- v).length();
}

float vec3d::length() const {
	return sqrt((x * x) + (y * y) + (z * z));
}

vec3d vec3d::move3d(const float distance, const float rotateRadian) const {
	return vec3d(this->x + distance* cos(rotateRadian), this->y + distance* sin(rotateRadian), z);
}

/*
 * setters & getters
 */
void vec3d::setZ(const float z) {
	this->z = z;
}

float vec3d::getZ() const {
	return this->z;
}