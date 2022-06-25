//
// Created by dubininvyu on 01.02.2022.
//

#include "geometry.h"

#include "boost/format.hpp"

using namespace std;
using namespace boost;
using namespace geometry;

// =============== constructors & destructors
vec4d::vec4d() : vec3d(0.0, 0.0, 0.0), a(0.0) {

}

vec4d::vec4d(const float x, const float y, const float z, const float a) : vec3d(x, y, z), a(a) {

}

vec4d::vec4d(const vec2d& v, const float z, const float a) : vec3d(v, z), a(a) {

}

vec4d::vec4d(const vec3d& v, const float a) : vec3d(v), a(a) {

}

vec4d::vec4d(const vec4d& v) : vec3d(v.x, v.y, v.z), a(v.a) {

}

// =============== operators
bool vec4d::operator==(const vec4d& v) const {
	return (x == v.x && y == v.y && z == v.z && a == v.a);
}

float& vec4d::operator[](unsigned int index) const {
	return *((float*)this + index);
}

// =============== methods
string vec4d::toString() const {
    format fmt = format("%s, a = %f") % vec3d::toString() % a;
    return fmt.str();
}

// =============== setters & getters
void vec4d::setA(const float a) {
	this->a = a;
}

float vec4d::getA() const {
	return this->a;
}