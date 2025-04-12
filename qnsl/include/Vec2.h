#pragma once
#include <cmath>

namespace qn {
class Vec2 {
public:
	int x;
	int y;
	int width;
	int height;

	Vec2();
	Vec2(int x, int y);

	Vec2& operator=(const Vec2& other);
	Vec2 operator+(Vec2& other);
	Vec2 operator+(int s);
	Vec2 operator-(Vec2& other);
	Vec2 operator-(int s);
	Vec2 operator*(Vec2& other);
	Vec2 operator*(int s);
	Vec2 operator/(Vec2& other);
	Vec2 operator/(int s);
	Vec2& operator+=(Vec2& other);
	Vec2& operator+=(int s);
	Vec2& operator-=(Vec2& other);
	Vec2& operator-=(int s);
	Vec2& operator*=(Vec2& other);
	Vec2& operator*=(int s);
	Vec2& operator/=(Vec2& other);
	Vec2& operator/=(int s);

	Vec2& normalize();
	int length();
};
} // namespace qn

// typedef Vec2 Size;