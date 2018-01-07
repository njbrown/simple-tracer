#pragma once

#include <QList>
#include <QVector>
#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>

class Ray;

struct Material
{

};

struct Hit
{
	QVector3D pos;
	float t;// distance along ray
	QVector3D normal;
	Material* material = nullptr;
};

class SceneObject
{
public:
	Scene* scene;

	QMatrix4x4 localTransform;
	QMatrix4x4 globalTransform;
	QVector<SceneObject*> children;
	SceneObject()
	{
		localTransform.setToIdentity();
		globalTransform.setToIdentity();
	}
	void addChild(SceneObject* child)
	{
		children.append(child);
		child->scene = this->scene;
		scene->addObjectToList(child);
	}

	virtual bool intersects(const Ray& ray, Hit& hit)
	{
		return false;
	}
};

class SphereObject : public SceneObject
{
public:
	float radius;

	bool intersects(const Ray& ray
		Hit& hit)
	{
		auto invGlob = globalTransform.inverted();
		QVector3D p = invGlob * ray.pos;;
		QVector3D d = (invGlob * QVector4D(ray.dir, 0)).toVector3D();

		QVector3D spherePos = QVector3D(0, 0, 0);

		QVector3D m = p - spherePos;
		float b = QVector3D::dotProduct(m, d);
		float c = QVector3D::dotProduct(m, m) - radius * radius;

		if (c > 0 && b > 0) return false;

		float discr = b * b - c;

		if (discr < 0) return false;

		t = -b - qSqrt(discr);

		if (t < 0) t = 0;

		hitPoint = p + t * d;
		hit.pos = globTransform * hitPoint;
		hit.t = t;
		hit.normal = hitPoint.normalized();
		hit.material = this->material;

		return true;
	}
};

class Scene
{
	SceneObject* root;

	//list of all objects
	QVector<SceneObject*> objects;
public:
	Scene()
	{
		root = new SceneObject();
		root->scene = this;
	}

	SceneObject* getRoot()
	{
		return root;
	}

	// should only be called by scene node when adding child node
	void addObjectToList(SceneObject* obj)
	{
		objects.append(obj);
	}
};