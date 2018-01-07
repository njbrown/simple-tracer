#include <QApplication>
#include "renderwindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	RenderWindow window(nullptr);
	window.show();

	app.exec();

	return 0;
}