//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "vec2d.h"
#include <string>

using namespace std;

namespace geometry {

class vec3d : public vec2d {
protected:
	float z;
public:
    /*
     * constructors & destructors
     */
	vec3d();
	vec3d(const float x, const float y, const float z);
	vec3d(const vec2d& v, const float z = 0.0);
	vec3d(const vec3d& v);

	/*
	 * operators
	 */
	vec3d operator-(const vec3d& v) const;
	vec3d operator+(const vec3d& v) const;
	vec3d operator*(const float value) const;
	vec3d operator*(const vec3d& v) const;
	vec3d operator/(const float value) const;
	vec3d operator/(const vec3d& v) const;
	bool operator==(const vec3d& v) const;
	bool operator!=(const vec3d& v) const;

	/*
	 * methods
	 */
	virtual string toString() const;

    float distance(const vec3d& v) const;
	virtual float length() const;

	vec3d move3d(const float distance, const float rotateRadian) const;

	/*
	 * setters & getters
	 */
	void setZ(const float z);
	float getZ() const;
};

}