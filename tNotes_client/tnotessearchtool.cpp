#include <QGroupBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include "tnotessearchtool.h"

tNotesSearchTool::tNotesSearchTool(QWidget *parent) 
	: QWidget(parent)
{
	searchToolGroupBox = new QGroupBox(tr("search tool"), this);

	searchToolLineEdit = new QLineEdit;

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(searchToolLineEdit, 0, Qt::AlignRight);

	searchToolGroupBox->setLayout(layout);

}
