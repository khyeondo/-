
#include "D3Render.h"

D3Render* D3Render::m_pinst = 0;

Vec3 D3Render::WorldToCamera(Camera& cam,Vec3 ver)
{
	Vec3 temp;
	temp = (ver - cam.GetPos()).RotateY(cam.GetAngleY());
	temp = temp.RotateX(cam.GetAngleX());
	return temp;
}

Vec2 D3Render::CameraToViewer(Camera& cam,Vec3 ver)
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
