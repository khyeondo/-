#include "Vec3.h"

float Vec3::Length()
{
	return sqrt(powf(x, 2.f) + powf(y, 2.f) + powf(z, 2.f));
}

Vec3 Vec3::Normalize()
{
	Vec3 temp;
	float f = this->Length();
	temp.x = x / f; temp.y = y / f; temp.z = z / f;
	return temp;
}

Vec3 Vec3::RotateX(float angle)
{
	Vec3 temp;
	temp.x = x;
	temp.y = y * cosf(angle) + z * sinf(angle);
	temp.z = z * cosf(angle) - y * sinf(angle);

	return temp;
}

Vec3 Vec3::RotateY(float angle)
{
	Vec3 temp;
	temp.x = x * cosf(angle) + z * sinf(angle);
	temp.y = y;
	temp.z = z * cosf(angle) - x * sinf(angle);

	return temp;
}

Vec3 Vec3::RotateZ(float angle)
{
	Vec3 temp;
	temp.x = x * cosf(angle) + y * sinf(angle);
	temp.y = y * cosf(angle) - x * sinf(angle);
	temp.z = z;

	return temp;
}