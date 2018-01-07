#pragma once

#include <QMatrix4x4>


struct View
{
	int width;
	int height;
};

struct Ray
{
	QVector3D pos;
	QVector3D dir;
};

class Camera
{
public:
	float fov;//radians
	float aspectRatio;
	float angle;//in degrees
	float nearClip;
	float farClip;

	float vrViewScale;

	QMatrix4x4 viewMatrix;
	QMatrix4x4 projMatrix;

	QVector3D pos;

	Camera()
	{
		angle = 45;
		nearClip = 0.1f;
		farClip = 1000.0f;
		aspectRatio = 1.0f;//assumes a square viewport by default

		pos = QVector3D(10, 10, 10);

		viewMatrix.setToIdentity();
		viewMatrix.lookAt(pos, QVector3D(0,0,0), QVector3D(0,1,0));

		projMatrix.setToIdentity();
		projMatrix.perspective(angle, aspectRatio, nearClip, farClip);
	}

	Ray getRay(int viewPortWidth, int viewPortHeight, int x, int y)
	{
		Ray ray;
		ray.pos = pos;

		float x = ((2.0f * pos.x()) / viewPortWidth) - 1.0f;
		float y = 1.0f - ((2.0f * pos.y()) / viewPortHeight);

		QVector4D ray = projMatrix.inverted() * QVector4D(x, y, -1.0f, 1.0f);
		ray.setZ(-1.0f);
		ray.setW(0.0f);
		ray = viewMatrix.inverted() * ray;

		ray.dir = ray.toVector3D().normalized();

		return ray;
	}
};