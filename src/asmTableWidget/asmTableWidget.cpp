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
	// �жϵ�ǰ�Ƿ���75%λ��
	if (value > ui.AsmTable->verticalScrollBar()->maximum() * 0.75)
	{
		readFileToTable();
	}
}

void AsmTableWidget::init()
{
	// m_asmFile��Ŀ���ļ�
	m_asmFile.setFileName(m_asmFilePath);
	m_asmFile.open(QIODevice::ReadOnly | QIODevice::Text);
	// ��ʧ�ܶ���
	Q_ASSERT(m_asmFile.isOpen());


	// ��ʼ����� ���ñ�ͷ
	ui.AsmTable->setColumnCount(1);
	ui.AsmTable->setHorizontalHeaderLabels(QStringList() << "Asm");
	readFileToTable();

	// ��ʼ���źŲ� table �����ź�
	connect(ui.AsmTable->verticalScrollBar(), &QScrollBar::valueChanged, this, &AsmTableWidget::on_table_valueChanged);
}

void AsmTableWidget::readFileToTable()
{
	QTextStream in(&m_asmFile);
	for (int i = 0; i < 100; i++)
	{
		// ����ȡ�������ݷ���ui.AsmTable�����
		QString line = in.readLine();
		ui.AsmTable->insertRow(ui.AsmTable->rowCount());
		ui.AsmTable->setItem(ui.AsmTable->rowCount() - 1, 0, new QTableWidgetItem(line));
	}
}