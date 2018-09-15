#pragma once
#include <math.h>
struct Vec3
{
public:
	float x, y, z;

	Vec3 operator + (Vec3 vec)
	{
		Vec3 temp;
		temp.x = x + vec.x;
		temp.y = y + vec.y;
		temp.z = z + vec.z;
		return temp;
	}
	Vec3 operator - (Vec3 vec) {
		Vec3 temp;
		temp.x = x - vec.x;
		temp.y = y - vec.y;
		temp.z = z - vec.z;
		return temp;
	}
	void operator += (Vec3 vec) {
		x = x + vec.x;
		y = y + vec.y;
		z = z + vec.z;
	}
	void operator -= (Vec3 vec) {
		x = x - vec.x;
		y = y - vec.y;
		z = z - vec.z;
	}

	//x√‡»∏¿¸
	Vec3 RotateX(float angle) {
		Vec3 temp;
		temp.x = x;
		temp.y = y * cosf(angle) + z * sinf(angle);
		temp.z = z * cosf(angle) - y * sinf(angle);

		return temp;
	}
	Vec3 RotateY(float angle)
	{
		Vec3 temp;
		temp.x = x * cosf(angle) + z * sinf(angle);
		temp.y = y;
		temp.z = z * cosf(angle) - x * sinf(angle);

		return temp;
	}
	Vec3 RotateZ(float angle)
	{
		Vec3 temp;
		temp.x = x * cosf(angle) + y * sinf(angle);
		temp.y = y * cosf(angle) - x * sinf(angle);
		temp.z = z;

		return temp;
	}
};

typedef Vec3 Vertex;