//
// Created by dubininvyu on 01.05.2022.
//

#include "geometry.h"

#include <cmath>

using namespace geometry;

vec2d::vec2d() : x(0.0), y(0.0) {

}

vec2d::vec2d(const float x, const float y) : x(x), y(y) {

}

vec2d::vec2d(const vec2d& v) : x(v.x), y(v.y) {

}

vec2d vec2d::operator-(const vec2d& v) const {
	return vec2d(this->x-v.x, this->y-v.y);
}

vec2d vec2d::operator+(const vec2d& v) {
	return vec2d(this->x+v.x, this->y+v.y);
}

vec2d vec2d::operator*(const float value) {
	return vec2d(this->x*value, this->y*value);
}

vec2d vec2d::operator*(const vec2d& v) {
	return vec2d(this->x*v.x, this->y*v.y);
}

vec2d vec2d::operator/(const float value) {
	return vec2d(this->x/value, this->y/value);
}

vec2d vec2d::operator/(const vec2d& v) {
	return vec2d(this->x/v.x, this->y/v.y);
}

bool vec2d::operator==(const vec2d& v) {
	return (this->x == v.x && this->y == v.y);
}

bool vec2d::operator!=(const vec2d& v) {
	return !(*this == v);
}

float vec2d::distance(const vec2d& v) {
	return (*this - v).length();
}

float vec2d::length() const {
	return sqrt(this->x* this->x + this->y* this->y);
}

void vec2d::move(const float distance, const float rotateRadian) {
	this->x += distance* cos(rotateRadian);
	this->y += distance* sin(rotateRadian);
}

vec2d vec2d::move2d(const float distance, const float rotateRadian) {
	return vec2d(this->x + distance* cos(rotateRadian), this->y + distance* sin(rotateRadian));
}

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