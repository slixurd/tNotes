#ifndef TNOTESTOOLBAR_H
#define TNOTESTOOLBAR_H

#include"Operation.h"

#include <QtWidgets/QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

class tNotesButton;
class tNotesSearchTool;
class tNotesLoginDialog;

class tNotesToolBar:public QWidget
{
    Q_OBJECT
public:
    tNotesToolBar(void);
    ~tNotesToolBar(void);
private:

    void setupActions();

	QHBoxLayout* mainLayout;
    QPushButton* loginButton;
    QPushButton* newnoteButton;
    QPushButton* trashButton;
    QPushButton* sysButton;
    tNotesSearchTool* searchTool;
	QLineEdit *searchLineEditsearch;
    QPushButton* searchButton;

    tNotesLoginDialog *dialogLogin;

private slots:
    void loginButtonClicked();

signals:
    void openLoginDialog();

};
#endif
