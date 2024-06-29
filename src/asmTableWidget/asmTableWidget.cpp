#include "asmTableWidget.h"

AsmTableWidget::AsmTableWidget(QString asmFilePath, QWidget* parent)
	: QWidget(parent)
	, m_asmFilePath(asmFilePath)
{
	ui.setupUi(this);
	init();
}

AsmTableWidget::~AsmTableWidget()
{

}

void AsmTableWidget::on_table_valueChanged(int value)
{
	// 判断当前是否到了75%位置
	if (value > ui.AsmTable->verticalScrollBar()->maximum() * 0.75)
	{
		readFileToTable();
	}
}

void AsmTableWidget::init()
{
	// m_asmFile打开目标文件
	m_asmFile.setFileName(m_asmFilePath);
	m_asmFile.open(QIODevice::ReadOnly | QIODevice::Text);
	// 打开失败断言
	Q_ASSERT(m_asmFile.isOpen());


	// 初始化表格 设置表头
	ui.AsmTable->setColumnCount(1);
	ui.AsmTable->setHorizontalHeaderLabels(QStringList() << "Asm");
	readFileToTable();

	// 初始化信号槽 table 滚动信号
	connect(ui.AsmTable->verticalScrollBar(), &QScrollBar::valueChanged, this, &AsmTableWidget::on_table_valueChanged);
}

void AsmTableWidget::readFileToTable()
{
	QTextStream in(&m_asmFile);
	for (int i = 0; i < 100; i++)
	{
		// 将读取到的数据放入ui.AsmTable表格中
		QString line = in.readLine();
		ui.AsmTable->insertRow(ui.AsmTable->rowCount());
		ui.AsmTable->setItem(ui.AsmTable->rowCount() - 1, 0, new QTableWidgetItem(line));
	}
}