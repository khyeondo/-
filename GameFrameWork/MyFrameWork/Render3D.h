#pragma once

#include "Camera.h"
#include "header.h"

class Render3D
{
#pragma region Single
private:
	static Render3D * m_pinst;
public:
	static Render3D * GetInst() {
		if (m_pinst == 0)
			m_pinst = new Render3D();
		return m_pinst;
	}
	static void DeleteSingle() {
		if (m_pinst != 0)
			delete m_pinst;
		m_pinst = 0;
	}
#pragma endregion
public:
	Render3D() {}
	~Render3D() {}

	Vec3 WorldToCamera(Camera& cam,Vec3 ver);
	Vec2 CameraToViewer(Camera& cam,Vec3 ver);
};