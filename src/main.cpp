#include <QWidget>
#include <QApplication>

#include "asmTableWidget.h"
#include "registerTableWidget.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	AsmTableWidget* widget = new AsmTableWidget("trace.log");
	widget->show();

	RegisterTableWidget* registerWidget = new RegisterTableWidget();
	registerWidget->show();

	QObject::connect(widget,&AsmTableWidget::changedAsmCmd , registerWidget,&RegisterTableWidget::changedAsmCmd);

	return app.exec();

}
