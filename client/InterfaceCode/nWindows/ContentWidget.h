#ifndef CONTENT_H
#define CONTENT_H

#include <QtWidgets/QMainWindow>
#include<QVBoxLayout>
#include "MyListView.h"
#include "MyListView2.h"
#include "MyEditPart.h"
class MyContentWidget:public QWidget
{
public:
	MyContentWidget(void);
	~MyContentWidget(void);

	QHBoxLayout* m_pMainLayout;
	MyListView* mListView;
	MyListView2* mListView2;
	MyEditPart* mEditPart;
};
#endif