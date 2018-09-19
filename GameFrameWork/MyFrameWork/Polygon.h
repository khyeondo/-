#pragma once

#include "Vec3.h"

struct CPolygon
{
public:
	Vec3 vertex[4];
	byte color[3];
	Vec3 normalVec;
	float brightness;

public:
	CPolygon(Vec3* arrVec, int r,int g, int b)
	{
		for (int i = 0; i < 4; i++)
		{
			vertex[i] = *(arrVec + i);
		}
		color[0] = r; color[1] = g; color[2] = b;

		normalVec = Vec3::Cross(vertex[1] - vertex[0], vertex[3] - vertex[0]).Normalize();
		brightness = 1;		
	}
};