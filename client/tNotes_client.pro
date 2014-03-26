#-------------------------------------------------
#
# Project created by QtCreator 2014-03-16T22:26:10
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tNotes_client
TEMPLATE = app


SOURCES += main.cpp\
        tnotesmainwindow.cpp \
    tnotestexteditor.cpp \
    tnotessearchtool.cpp \
    json/json_internalarray.inl \
    json/json_internalmap.inl \
    json/json_reader.cpp \
    json/json_value.cpp \
    json/json_valueiterator.inl \
    json/json_writer.cpp \
    operation.cpp \
    tnoteslogindialog.cpp \
    search.cpp \
    tnotestitlebar.cpp \
    tnotestoolbar.cpp \
    tnotescontentwidget.cpp \
    tnotesbookcaterorylist.cpp \
    tnotescategorylist.cpp \
    tnotesstatusbar.cpp \
    tnotesbutton.cpp \
    MyQItemDelegate.cpp \
    tnoteseditlinkdialog.cpp

HEADERS  += tnotesmainwindow.h \
    tnotestexteditor.h \
    tnotessearchtool.h \
    json/autolink.h \
    json/config.h \
    json/features.h \
    json/forwards.h \
    json/json.h \
    json/json_batchallocator.h \
    json/reader.h \
    json/value.h \
    json/writer.h \
    Directory.h \
    Operation.h \
    Article.h \
    tnoteslogindialog.h \
    friso.h \
    friso_API.h \
    search.h \
    tnotestitlebar.h \
    tnotestoolbar.h \
    tnotescontentwidget.h \
    tnotescategorylist.h \
    tnotesbookcategorylist.h \
    tnotesstatusbar.h \
    tnotesbutton.h \
    MyQItemDelegate.h \
    tnoteseditlinkdialog.h

OTHER_FILES += \
    json/sconscript \
    medias/icons/settings.png \
    medias/icons/sync.png

RESOURCES += \
    tNotesRes.qrc

#请把"C:/Users/smallway/Qt/untitled6/"修改为本机friso.lib文件的绝对地址
LIBS+= -LD:\Tencent\tNotes\client\libs -lfriso
