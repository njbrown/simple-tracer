#include <QMainWindow>

class RenderWindow : public QMainWindow
{
public:
	RenderWindow(QWidget* parent):
		QMainWindow(parent)
	{
		this->setMinimumSize(QSize(800, 600));

	}
};