#pragma once

#include <QObject>
#include <QWidget>

#include "ui_DebugRegister.h"
//
class RegisterTableWidget : public QWidget
{
public:
	RegisterTableWidget(QWidget* parent = nullptr);
	~RegisterTableWidget();

private:
	void init();
	QStringList splitRegs(const QString& regs);

public slots:
	void changedAsmCmd(const QString& regs);

private:
	Ui::Register ui;
};