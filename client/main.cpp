#include "tnotesmainwindow.h"
#include "Operation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tNotesMainWindow w;

    w.show();
//Directory d("001","diyige","d","d",0);
//createRoot(d);
//Article aa("0001","第一篇文章","没有内容","s","s",0);
//createArticle("001",aa);

    return a.exec();
}
