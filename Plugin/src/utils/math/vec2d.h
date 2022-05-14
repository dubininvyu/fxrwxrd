//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

namespace geometry {

class vec2d {
protected:
	float x;
	float y;
public:
	vec2d();
	vec2d(const float x, const float y);
	vec2d(const vec2d& v);

	vec2d operator-(const vec2d& v) const;
	vec2d operator+(const vec2d& v);
	vec2d operator*(const float value);
	vec2d operator*(const vec2d& v);
	vec2d operator/(const float value);
	vec2d operator/(const vec2d& v);
	bool operator==(const vec2d& v);
	bool operator!=(const vec2d& v);

	float distance(const vec2d& v);
	float length() const;

	void move(const float distance, const float rotateRadian);
	vec2d move2d(const float distance, const float rotateRadian);

	void setX(const float x);
	float getX() const;

	void setY(const float y);
	float getY() const;
};

}