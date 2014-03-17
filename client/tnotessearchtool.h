#ifndef TNOTESSEARCHTOOL_H
#define TNOTESSEARCHTOOL_H

#include <QWidget>
class QGroupBox;
class QLineEdit;

class tNotesSearchTool : public QWidget
{
	Q_OBJECT

public:
		tNotesSearchTool(QWidget *parent = 0);

private:
		QGroupBox *searchToolGroupBox;
		QLineEdit *searchToolLineEdit;

};

#endif
