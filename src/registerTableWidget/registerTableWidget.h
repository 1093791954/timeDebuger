#pragma once

#include <QObject>
#include <QWidget>

#include "ui_DebugRegister.h"
//
class RegisterTableWidget : public QWidget
{
	public:
		RegisterTableWidget(QWidget *parent = nullptr);
		~RegisterTableWidget();
	private:
		Ui::Register ui;
};