#include "MyStatusBar.h"
#include "nwindows.h"

MyStatusBar::MyStatusBar(void)
{
	setStyleSheet(readFile("asset/qss/mystatusbar.qss"));
}


MyStatusBar::~MyStatusBar(void)
{

}
