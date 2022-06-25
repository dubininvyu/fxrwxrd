//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include <string>

using namespace std;

namespace geometry {

class vec2d {
protected:
	float x;
	float y;
public:
    /*
     * constructors & destructors
     */
	vec2d();
	vec2d(const float x, const float y);
	vec2d(const vec2d& v);

	/*
	 * operators
	 */
	vec2d operator-(const vec2d& v) const;
	vec2d operator+(const vec2d& v) const;
	vec2d operator*(const float value) const;
	vec2d operator*(const vec2d& v) const;
	vec2d operator/(const float value) const;
	vec2d operator/(const vec2d& v) const;
	bool operator==(const vec2d& v) const;
	bool operator!=(const vec2d& v) const;

	/*
	 * methods
	 */
	virtual string toString() const;

	float distance(const vec2d& v) const;
	virtual float length() const;

	void move(const float distance, const float rotateRadian);
	vec2d move2d(const float distance, const float rotateRadian) const;

	/*
	 * setters & getters
	 */
	void setX(const float x);
	float getX() const;

	void setY(const float y);
	float getY() const;
};

}