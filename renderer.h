#pragma once

#include <QImage>
#include "camera.h"
#include "scene.h"


class Renderer
{
	struct Color
	{
		float r, g, b;

		Color()
		{
			r = g = b = 0;
		}

		Color(float r, float g, float b):
			r(r),g(g),b(b)
		{
		}
	};

	class Image
	{
	public:
		Color* data;
		int width;
		int height;

		Image(int width, int height):
			width(width),
			height(height)
		{
			data = new Color[width * height];
		}

		void setPixel(int x, int y,float r, float g, float b)
		{
			data[width * y + x] = Color(r,g,b);
		}

		Color getPixel(int x, int y)
		{
			return data[width * y + x];
		}

		QImage toQImage()
		{
			QImage image(width, height, QImage::Format_RGB32);

			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++)
				{
					auto color = getPixel(x, y);
					image.setPixel(x,y,qRgb(color.r, color.g, color.b));
				}
			}

			return image;
		}
	};

public:
	QImage renderScene(const Scene& scene, const Camera& camera, const View& view)
	{
		Image* image = new Image(view.width, view.height);

		return image->toQImage();
	}

	Color trace(const Scene& scene, const Ray& ray)
	{

	}

};