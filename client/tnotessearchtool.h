#ifndef TNOTESSEARCHTOOL_H
#define TNOTESSEARCHTOOL_H

#include <QWidget>
class QGroupBox;
class QLineEdit;
class QPushButton;
class QLabel;
class tNotesButton;

class tNotesSearchTool : public QWidget
{
	Q_OBJECT

public:
		tNotesSearchTool(QWidget *parent = 0);
        bool find(const std::string str);
private:
		QGroupBox *searchToolGroupBox;
		QLineEdit *searchToolLineEdit;
    tNotesButton *searchbtn;
        QLabel *searchStateLabel;
private slots:
    void searchbtn_click();
};

#endif
