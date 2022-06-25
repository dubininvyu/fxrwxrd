//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "vec2d.h"
#include "vec3d.h"
#include <string>

using namespace std;

namespace geometry {

class vec4d : public vec3d {
protected:
	float a;
public:
    /*
     * constructors & destructors
     */
	vec4d();
	vec4d(const float x, const float y, const float z, const float a);
	vec4d(const vec2d& v, const float z = 0.0, const float r = 0.0);
	vec4d(const vec3d& v, const float r = 0.0);
	vec4d(const vec4d& v);

	/*
	 * operators
	 */
	bool operator==(const vec4d& v) const;
	float& operator[](unsigned int index) const;

	/*
	 * methods
	 */
    virtual string toString() const;

    /*
     * setters & getters
     */
	void setA(const float r);
	float getA() const;
};

}