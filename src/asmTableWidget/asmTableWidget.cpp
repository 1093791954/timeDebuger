
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
	// 初始化 m_stream
	m_stream.setDevice(&m_asmFile);

	// 初始化表格 设置表头
	QStringList headers = QStringList() << "地址" << "汇编指令";
	ui.AsmTable->setColumnCount(headers.size());
	ui.AsmTable->setHorizontalHeaderLabels(headers);
	// 设置第一列列宽度
	ui.AsmTable->setColumnWidth(0, 100);
	// 设置第二列列宽度为自适应
	ui.AsmTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	// 设置表格不可编辑
	ui.AsmTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	// 设置表格不可排序
	ui.AsmTable->setSortingEnabled(false);

	readFileToTable();

	// 初始化信号槽 table 滚动信号
	connect(ui.AsmTable->verticalScrollBar(), &QScrollBar::valueChanged, this, &AsmTableWidget::on_table_valueChanged);
}

void AsmTableWidget::readFileToTable()
{
	// 如果是第一次读取，则从第五行开始读取
	if (ui.AsmTable->rowCount() == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			m_stream.readLine(); // 读取不保存
		}
		QString registerLine = m_stream.readLine(); // 所有寄存器
		QString emptyLine = m_stream.readLine();
	}

	for (int i = 0; i < 100; i++)
	{
		// 判断是否已经读物完毕，读取完毕则直接返回
		if (m_stream.atEnd())
		{
			return;
		}
		// 将读取到的数据放入ui.AsmTable表格中
		QString asmCmdLine = m_stream.readLine();
		qDebug() << "asmCmdLine:" << asmCmdLine;
		QString registerLine = m_stream.readLine();
		m_stream.readLine(); // QString emptyLine

		QStringList result = splitLogCmd(asmCmdLine);

		// 将 asmLine内容添加到表格中
		int RowCont;
		RowCont = ui.AsmTable->rowCount();
		ui.AsmTable->insertRow(RowCont);//增加一行

		//插入元素
		ui.AsmTable->setItem(RowCont, 0, new QTableWidgetItem(result.at(0)));
		ui.AsmTable->setItem(RowCont, 1, new QTableWidgetItem(result.at(1)));
		
		m_dirToReg.insert(std::make_pair(result.at(0),registerLine));
	}
}

QStringList AsmTableWidget::splitLogCmd(QString line)
{
	QStringList result;
	// 使用空格分割 
	QStringList splitList = line.split(" ");

	result.append(splitList.at(0)); // 地址
	result.append(line.mid(splitList.at(0).length() + 1));

	return result;
}
