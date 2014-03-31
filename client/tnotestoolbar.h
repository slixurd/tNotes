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
    QPushButton* newDirectoryButton;
    QPushButton* newArticleButton;
    QPushButton* deleteArticleButton;
    QPushButton* deleteDirectoryButton;
    QPushButton* sysButton;
    tNotesSearchTool* searchTool;
private:

    void setupActions();
	QHBoxLayout* mainLayout;
    QPushButton* loginButton;
	QLineEdit *searchLineEditsearch;
    QPushButton* searchButton;

    tNotesLoginDialog *dialogLogin;

private slots:
    void loginButtonClicked();

signals:
    void openLoginDialog();

};
#endif
