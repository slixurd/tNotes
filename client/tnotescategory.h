#ifndef TNOTESCATEGORY_H
#define TNOTESCATEGORY_H

#include <QStandardItemModel>

#include <QWidget>
class QTableView;
class QGroupBox;

class tNotesCategory : public QWidget
{
	Q_OBJECT

public:
		tNotesCategory(QWidget *parent = 0);

private:
		QGroupBox *noteGroupBox;
		QStandardItemModel *model;
		QTableView *noteCategory;
};

#endif // TNOTESCATEGORY_H
