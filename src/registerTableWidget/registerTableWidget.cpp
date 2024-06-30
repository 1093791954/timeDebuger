#include "registerTableWidget.h"

RegisterTableWidget::RegisterTableWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

RegisterTableWidget::~RegisterTableWidget()
{

}

void RegisterTableWidget::init()
{
	// 初始化表格
	QStringList headers = QStringList() << "寄存器" << "值";
	ui.RegisterTable->setColumnCount(headers.size());
	ui.RegisterTable->setHorizontalHeaderLabels(headers);
	// 设置第一列宽度
	ui.RegisterTable->setColumnWidth(0, 100);
	ui.RegisterTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

	// 填充默认寄存器数据
	for (int i = 0; i < 35; i++)
	{
		ui.RegisterTable->insertRow(ui.RegisterTable->rowCount());//增加一行
	}

	ui.RegisterTable->setItem(0, 0, new QTableWidgetItem("x0"));
	ui.RegisterTable->setItem(1, 0, new QTableWidgetItem("x1"));
	ui.RegisterTable->setItem(2, 0, new QTableWidgetItem("x2"));
	ui.RegisterTable->setItem(3, 0, new QTableWidgetItem("x3"));
	ui.RegisterTable->setItem(4, 0, new QTableWidgetItem("x4"));
	ui.RegisterTable->setItem(5, 0, new QTableWidgetItem("x5"));
	ui.RegisterTable->setItem(6, 0, new QTableWidgetItem("x6"));
	ui.RegisterTable->setItem(7, 0, new QTableWidgetItem("x7"));
	ui.RegisterTable->setItem(8, 0, new QTableWidgetItem("x8"));
	ui.RegisterTable->setItem(9, 0, new QTableWidgetItem("x9"));
	ui.RegisterTable->setItem(10, 0, new QTableWidgetItem("x10"));
	ui.RegisterTable->setItem(11, 0, new QTableWidgetItem("x11"));
	ui.RegisterTable->setItem(12, 0, new QTableWidgetItem("x12"));
	ui.RegisterTable->setItem(13, 0, new QTableWidgetItem("x13"));
	ui.RegisterTable->setItem(14, 0, new QTableWidgetItem("x14"));
	ui.RegisterTable->setItem(15, 0, new QTableWidgetItem("x15"));
	ui.RegisterTable->setItem(16, 0, new QTableWidgetItem("x16"));
	ui.RegisterTable->setItem(17, 0, new QTableWidgetItem("x17"));
	ui.RegisterTable->setItem(18, 0, new QTableWidgetItem("x18"));
	ui.RegisterTable->setItem(19, 0, new QTableWidgetItem("x19"));
	ui.RegisterTable->setItem(20, 0, new QTableWidgetItem("x20"));
	ui.RegisterTable->setItem(21, 0, new QTableWidgetItem("x21"));
	ui.RegisterTable->setItem(22, 0, new QTableWidgetItem("x22"));
	ui.RegisterTable->setItem(23, 0, new QTableWidgetItem("x23"));
	ui.RegisterTable->setItem(24, 0, new QTableWidgetItem("x24"));
	ui.RegisterTable->setItem(25, 0, new QTableWidgetItem("x25"));
	ui.RegisterTable->setItem(26, 0, new QTableWidgetItem("x26"));
	ui.RegisterTable->setItem(27, 0, new QTableWidgetItem("x27"));
	ui.RegisterTable->setItem(28, 0, new QTableWidgetItem("x28"));
	ui.RegisterTable->setItem(29, 0, new QTableWidgetItem("x29"));
	ui.RegisterTable->setItem(30, 0, new QTableWidgetItem("fp"));
	ui.RegisterTable->setItem(31, 0, new QTableWidgetItem("lr"));
	ui.RegisterTable->setItem(32, 0, new QTableWidgetItem("pc"));
	ui.RegisterTable->setItem(33, 0, new QTableWidgetItem("sp"));
	ui.RegisterTable->setItem(34, 0, new QTableWidgetItem("nzcv"));

}

QStringList RegisterTableWidget::splitRegs(const QString& regs)
{
	QStringList ret;

	QStringList splitRet = regs.split(" ");
	if (splitRet.size() != 35) return ret; // 校验长度 ， 不足35个寄存器 无效
	for (int i = 0; i < splitRet.size(); i++)
	{
		QStringList splitReg = splitRet.at(i).split(":");
		ret.push_back(splitReg.at(1));
	}

	return ret;

}

void RegisterTableWidget::changedAsmCmd(const QString& regs)
{
	QStringList ret =  splitRegs(regs);
	if (ret .size() != 35)
	{
		return;
	}

	for (int i = 0; i < 35; i++)
	{
		ui.RegisterTable->setItem(i, 1, new QTableWidgetItem(ret.at(i)));
	}

}