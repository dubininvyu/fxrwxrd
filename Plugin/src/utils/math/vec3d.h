//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "vec2d.h"

namespace geometry {

class vec3d : public vec2d {
protected:
	float z;
public:
	vec3d();
	vec3d(const float x, const float y, const float z);
	vec3d(const vec2d& v, const float z = 0.0);
	vec3d(const vec3d& v);

	vec3d operator-(const vec3d& v);
	vec3d operator+(const vec3d& v);
	vec3d operator*(const float value);
	vec3d operator*(const vec3d& v);
	vec3d operator/(const float value);
	vec3d operator/(const vec3d& v);
	bool operator==(const vec3d& v);
	bool operator!=(const vec3d& v);

	float distance(const vec3d& v);
	float length() const;

	vec3d move3d(const float distance, const float rotateRadian);

	void setZ(const float z);
	float getZ() const;
};

}