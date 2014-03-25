#ifndef TNOTESTOOLBAR_H
#define TNOTESTOOLBAR_H

#include <QtWidgets/QMainWindow>
#include<QVBoxLayout>
#include <QLineEdit>


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
    tNotesButton* loginButton;
    tNotesButton* newnoteButton;
    tNotesButton* trashButton;
    tNotesButton* sysButton;
    tNotesSearchTool* searchTool;
	QLineEdit *searchLineEditsearch;
    tNotesButton* searchButton;

    tNotesLoginDialog *dialogLogin;

private slots:
    void loginButtonClicked();

signals:
    void openLoginDialog();

};
#endif
