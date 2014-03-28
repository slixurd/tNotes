#include "tnotesstatusbar.h"
#include "Operation.h"
tNotesStatusBar::tNotesStatusBar(void)
{
    setStyleSheet(readFile(":/qss/mystatusbar.qss"));
}


tNotesStatusBar::~tNotesStatusBar(void)
{

}
