#pragma once

#include "Camera.h"
#include "header.h"

class D3Render
{
#pragma region Single
private:
	static D3Render * m_pinst;
public:
	static D3Render * GetInst() {
		if (m_pinst == 0)
			m_pinst = new D3Render();
		return m_pinst;
	}
	static void DeleteSingle() {
		if (m_pinst != 0)
			delete m_pinst;
		m_pinst = 0;
	}
#pragma endregion
public:
	D3Render() {}
	~D3Render() {}

	Vec3 WorldToCamera(Camera& cam,Vec3 ver);
	Vec2 CameraToViewer(Camera& cam,Vec3 ver);
};