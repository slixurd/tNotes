#include "mythread.h"
#include "tnotessearchtool.h"

myThread::myThread(QObject *parent) :
    QThread(parent)
{
}

void myThread::run()
{
    tNotesSearchTool::build();
}
