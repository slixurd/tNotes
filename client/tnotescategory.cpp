#include <QTableView>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSizePolicy>
#include "tnotescategory.h"

tNotesCategory::tNotesCategory(QWidget *parent)
	: QWidget(parent)
{
	noteGroupBox = new QGroupBox(tr("Notes"), this);

	model = new QStandardItemModel(5, 1, this);
	noteCategory = new QTableView;
	noteCategory->setModel(model);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(noteCategory, Qt::AlignTop);

	noteGroupBox->setLayout(layout);
    noteGroupBox->setMinimumSize(this->width(),
			this->height());

}
