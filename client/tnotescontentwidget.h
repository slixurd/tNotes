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
public:
    tNotesContentWidget(void);
    ~tNotesContentWidget(void);
public:
    QSplitter *splitter;
	QHBoxLayout* m_pMainLayout;
    tNotesBookCategoryList* mListView;
    tNotesCategoryList* mListView2;
    tNotesTextEditor* mEditPart;
};
#endif
