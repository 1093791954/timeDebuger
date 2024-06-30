#include <QWidget>
#include <QApplication>

#include "asmTableWidget.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	AsmTableWidget* widget = new AsmTableWidget("trace.log");
	widget->show();

	return app.exec();
}
