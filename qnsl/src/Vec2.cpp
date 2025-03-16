#include "Vec2.h"

qn::Vec2::Vec2() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}

qn::Vec2::Vec2(int x, int y) {
	this->x = x;
	this->y = y;
	this->width = x;
	this->height = y;
}

qn::Vec2& qn::Vec2::operator=(const qn::Vec2& other) {
	if (this == &other) return *this;

	this->x = other.x;
	this->y = other.y;
	this->width = this->x;
	this->height = this->y;

	return *this;
}

qn::Vec2 qn::Vec2::operator+(qn::Vec2& other) {
	qn::Vec2 res;
	res.x = this->x + other.x;
	res.y = this->y + other.y;
	res.width = res.x;
	res.height = res.y;
	return res;
}

qn::Vec2 qn::Vec2::operator+(int s) {
	qn::Vec2 res;
	res.x = this->x + s;
	res.y = this->y + s;
	res.width = res.x;
	res.height = res.y;
	return res;
}

qn::Vec2 qn::Vec2::operator-(qn::Vec2& other) {
	qn::Vec2 res;
	res.x = this->x - other.x;
	res.y = this->y - other.y;
	res.width = res.x;
	res.height = res.y;
	return res;
}

qn::Vec2 qn::Vec2::operator-(int s) {
	qn::Vec2 res;
	res.x = this->x - s;
	res.y = this->y - s;
	res.width = res.x;
	res.height = res.y;
	return res;
}

qn::Vec2 qn::Vec2::operator*(qn::Vec2& other) {
	qn::Vec2 res;
	res.x = this->x * other.x;
	res.y = this->y * other.y;
	res.width = res.x;
	res.height = res.y;
	return res;
}

qn::Vec2 qn::Vec2::operator*(int s) {
	qn::Vec2 res;
	res.x = this->x * s;
	res.y = this->y * s;
	res.width = res.x;
	res.height = res.y;
	return res;
}

qn::Vec2 qn::Vec2::operator/(qn::Vec2& other) {
	qn::Vec2 res;
	res.x = this->x / other.x;
	res.y = this->y / other.y;
	res.width = res.x;
	res.height = res.y;
	return res;
}

qn::Vec2 qn::Vec2::operator/(int s) {
	qn::Vec2 res;
	res.x = this->x / s;
	res.y = this->y / s;
	res.width = res.x;
	res.height = res.y;
	return res;
}

qn::Vec2& qn::Vec2::operator+=(qn::Vec2& other) {
	this->x += other.x;
	this->y += other.y;
	this->width = this->x;
	this->height = this->y;
	return *this;
}

qn::Vec2& qn::Vec2::operator+=(int s) {
	this->x += s;
	this->y += s;
	this->width = this->x;
	this->height = this->y;
	return *this;
}

qn::Vec2& qn::Vec2::operator-=(qn::Vec2& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->width = this->x;
	this->height = this->y;
	return *this;
}

qn::Vec2& qn::Vec2::operator-=(int s) {
	this->x -= s;
	this->y -= s;
	this->width = this->x;
	this->height = this->y;
	return *this;
}

qn::Vec2& qn::Vec2::operator*=(qn::Vec2& other) {
	this->x *= other.x;
	this->y *= other.y;
	this->width = this->x;
	this->height = this->y;
	return *this;
}

qn::Vec2& qn::Vec2::operator*=(int s) {
	this->x *= s;
	this->y *= s;
	this->width = this->x;
	this->height = this->y;
	return *this;
}

qn::Vec2& qn::Vec2::operator/=(qn::Vec2& other) {
	this->x /= other.x;
	this->y /= other.y;
	this->width = this->x;
	this->height = this->y;
	return *this;
}

qn::Vec2& qn::Vec2::operator/=(int s) {
	this->x /= s;
	this->y /= s;
	this->width = this->x;
	this->height = this->y;
	return *this;
}

qn::Vec2& qn::Vec2::normalize() {
	if (length() == 0) return *this;
	*this *= (1 / length());
	return *this;
}

int qn::Vec2::length() {
	return (int)(std::sqrt(x * x + y * y));
}