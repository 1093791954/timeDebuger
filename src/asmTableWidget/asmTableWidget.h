#pragma once

#include <QWidget>
#include <QString>
#include <QFile>
#include <QScrollBar>

#include "ui_DebugAssembly.h"

class AsmTableWidget : public QWidget
{
	Q_OBJECT
public:
	AsmTableWidget(QString asmFilePath, QWidget* parent = nullptr);
	~AsmTableWidget();

private slots:
	// 滚动条改变
	void on_table_valueChanged(int value);

private:
	void init();
	void readFileToTable();
private:
	Ui::DebugAssembly ui;

	QString m_asmFilePath;
	QFile m_asmFile;

};