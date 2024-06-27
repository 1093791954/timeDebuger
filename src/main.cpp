#include <QWidget>
#include <QApplication>


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget w;
	w.resize(640, 480);
	w.setWindowTitle("Hello World");
	w.show();
	return app.exec();
}
