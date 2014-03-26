/****************************************************************************
** Meta object code from reading C++ file 'tnotesmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/tnotesmainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tnotesmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tNotesMainWindow_t {
    QByteArrayData data[34];
    char stringdata[373];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_tNotesMainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_tNotesMainWindow_t qt_meta_stringdata_tNotesMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 13),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 10),
QT_MOC_LITERAL(4, 43, 7),
QT_MOC_LITERAL(5, 51, 9),
QT_MOC_LITERAL(6, 61, 8),
QT_MOC_LITERAL(7, 70, 11),
QT_MOC_LITERAL(8, 82, 17),
QT_MOC_LITERAL(9, 100, 7),
QT_MOC_LITERAL(10, 108, 7),
QT_MOC_LITERAL(11, 116, 15),
QT_MOC_LITERAL(12, 132, 4),
QT_MOC_LITERAL(13, 137, 12),
QT_MOC_LITERAL(14, 150, 6),
QT_MOC_LITERAL(15, 157, 9),
QT_MOC_LITERAL(16, 167, 14),
QT_MOC_LITERAL(17, 182, 20),
QT_MOC_LITERAL(18, 203, 10),
QT_MOC_LITERAL(19, 214, 17),
QT_MOC_LITERAL(20, 232, 8),
QT_MOC_LITERAL(21, 241, 8),
QT_MOC_LITERAL(22, 250, 4),
QT_MOC_LITERAL(23, 255, 4),
QT_MOC_LITERAL(24, 260, 6),
QT_MOC_LITERAL(25, 267, 15),
QT_MOC_LITERAL(26, 283, 15),
QT_MOC_LITERAL(27, 299, 11),
QT_MOC_LITERAL(28, 311, 9),
QT_MOC_LITERAL(29, 321, 7),
QT_MOC_LITERAL(30, 329, 11),
QT_MOC_LITERAL(31, 341, 5),
QT_MOC_LITERAL(32, 347, 11),
QT_MOC_LITERAL(33, 359, 12)
    },
    "tNotesMainWindow\0initNotebooks\0\0"
    "Directory*\0dirList\0initNotes\0Article*\0"
    "articleList\0initNotesContents\0Article\0"
    "article\0updateNotebooks\0path\0updateEditor\0"
    "string\0articleId\0minimizeWindow\0"
    "maxmizeRestoreWindow\0maxRestore\0"
    "userAuthenticated\0QString&\0username\0"
    "pass\0int&\0Sindex\0openLoginDialog\0"
    "createDirectory\0saveArticle\0moveStart\0"
    "moveEnd\0clickedBook\0index\0clickedNote\0"
    "newDirectory\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tNotesMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06,
       5,    1,   97,    2, 0x06,
       8,    1,  100,    2, 0x06,
      11,    1,  103,    2, 0x06,
      13,    1,  106,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      16,    0,  109,    2, 0x08,
      17,    1,  110,    2, 0x08,
      19,    3,  113,    2, 0x08,
      25,    0,  120,    2, 0x08,
      26,    0,  121,    2, 0x08,
      27,    0,  122,    2, 0x08,
      28,    1,  123,    2, 0x08,
      29,    1,  126,    2, 0x08,
      30,    1,  129,    2, 0x08,
      32,    1,  132,    2, 0x08,
      33,    0,  135,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 14,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 23,   21,   22,   24,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QModelIndex,   31,
    QMetaType::Void, QMetaType::QModelIndex,   31,
    QMetaType::Void,

       0        // eod
};

void tNotesMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tNotesMainWindow *_t = static_cast<tNotesMainWindow *>(_o);
        switch (_id) {
        case 0: _t->initNotebooks((*reinterpret_cast< Directory*(*)>(_a[1]))); break;
        case 1: _t->initNotes((*reinterpret_cast< Article*(*)>(_a[1]))); break;
        case 2: _t->initNotesContents((*reinterpret_cast< Article(*)>(_a[1]))); break;
        case 3: _t->updateNotebooks((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->updateEditor((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 5: _t->minimizeWindow(); break;
        case 6: _t->maxmizeRestoreWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->userAuthenticated((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->openLoginDialog(); break;
        case 9: { bool _r = _t->createDirectory();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->saveArticle();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: _t->moveStart((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 12: _t->moveEnd((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 13: _t->clickedBook((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->clickedNote((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->newDirectory(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (tNotesMainWindow::*_t)(Directory * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesMainWindow::initNotebooks)) {
                *result = 0;
            }
        }
        {
            typedef void (tNotesMainWindow::*_t)(Article * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesMainWindow::initNotes)) {
                *result = 1;
            }
        }
        {
            typedef void (tNotesMainWindow::*_t)(Article );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesMainWindow::initNotesContents)) {
                *result = 2;
            }
        }
        {
            typedef void (tNotesMainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesMainWindow::updateNotebooks)) {
                *result = 3;
            }
        }
        {
            typedef void (tNotesMainWindow::*_t)(string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesMainWindow::updateEditor)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject tNotesMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_tNotesMainWindow.data,
      qt_meta_data_tNotesMainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *tNotesMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tNotesMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tNotesMainWindow.stringdata))
        return static_cast<void*>(const_cast< tNotesMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int tNotesMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void tNotesMainWindow::initNotebooks(Directory * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tNotesMainWindow::initNotes(Article * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void tNotesMainWindow::initNotesContents(Article _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void tNotesMainWindow::updateNotebooks(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void tNotesMainWindow::updateEditor(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
