#ifndef TNOTESCONTENTWIDGET_H
#define TNOTESCONTENTWIDGET_H

#include <QtWidgets/QMainWindow>
#include<QVBoxLayout>
#include "tnotesbookcategorylist.h"
#include "tnotescategorylist.h"
//#include "MyEditPart.h"
#include "tnotestexteditor.h"

class QSplitter;
class tNotesContentWidget:public QWidget
{
    Q_OBJECT
public:
    tNotesContentWidget(void);
    ~tNotesContentWidget(void);
public:
    QSplitter *splitter;
	QHBoxLayout* m_pMainLayout;
    tNotesBookCategoryList* mListView;
    tNotesCategoryList* mListView2;
    tNotesTextEditor* mEditPart;

private:
    void setupLayout();
    void setupActions();

signals:
    void updateNotebooks(QString path);

public slots:
    void updateContents(QString path);
};
#endif
