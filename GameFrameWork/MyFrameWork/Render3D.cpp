
#include "Render3D.h"

Render3D* Render3D::m_pinst = 0;

Vec3 Render3D::WorldToCamera(Camera& cam,Vec3 ver)
{
	Vec3 temp;
	temp = (ver - cam.GetPos()).RotateX(cam.GetAngleX());
	temp = temp.RotateY(cam.GetAngleY());
	return temp;
}

Vec2 Render3D::CameraToViewer(Camera& cam,Vec3 ver)
{
	Vec2 pos;
	//float temp = (cam.y - ver.y);
	if (ver.z == 0) {
		pos.x = ver.x;
		pos.y = ver.y;
	}
	else {
		float temp = cam.GetDist()*2 / ver.z;
		pos.x = ver.x * temp + cam.GetWidth()/2;
		pos.y = ver.y * temp + cam.GetHeight()/2;
	}

	return pos;
}
