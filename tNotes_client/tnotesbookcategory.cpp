#include <QTableView>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSizePolicy>
#include "tnotesbookcategory.h"

tNotesBookCategory::tNotesBookCategory(QWidget *parent)
	: QWidget(parent)
{
	notebookGroupBox = new QGroupBox(tr("NoteBook"), this);

	model = new QStandardItemModel(5, 1, this);
	notebookCategory = new QTableView;
	notebookCategory->setModel(model);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(notebookCategory, Qt::AlignTop);

	notebookGroupBox->setLayout(layout);
	notebookGroupBox->setMinimumSize(this->width(),
			this->height());

}
