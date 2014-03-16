#include "tnotesmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tNotesMainWindow w;
    w.show();

    return a.exec();
}
