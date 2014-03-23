#include "nwindows.h"
#include "MyTreeView.h"
#include "MyListView.h"
#include <QtWidgets/QApplication>
#include <QTreeView>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv); 
	nWindows MyWindows; 
	MyWindows.show();  
	return app.exec();
}
