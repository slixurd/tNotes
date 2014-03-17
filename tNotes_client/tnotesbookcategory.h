#ifndef TNOTESBOOKCATEGORY_H
#define TNOTESBOOKCATEGORY_H

#include <QStandardItemModel>

#include <QWidget>
class QTableView;
class QGroupBox;

class tNotesBookCategory : public QWidget
{
	Q_OBJECT

public:
		tNotesBookCategory(QWidget *parent = 0);

private:
		QGroupBox *notebookGroupBox;
		QStandardItemModel *model;
		QTableView *notebookCategory;
};

#endif // TNOTESBOOKCATEGORY_H
