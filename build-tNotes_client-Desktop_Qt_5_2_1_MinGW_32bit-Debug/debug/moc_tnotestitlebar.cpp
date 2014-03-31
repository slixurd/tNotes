/****************************************************************************
** Meta object code from reading C++ file 'tnotestitlebar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/tnotestitlebar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tnotestitlebar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tNotesTitleBar_t {
    QByteArrayData data[10];
    char stringdata[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_tNotesTitleBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_tNotesTitleBar_t qt_meta_stringdata_tNotesTitleBar = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 14),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 20),
QT_MOC_LITERAL(4, 52, 11),
QT_MOC_LITERAL(5, 64, 9),
QT_MOC_LITERAL(6, 74, 7),
QT_MOC_LITERAL(7, 82, 13),
QT_MOC_LITERAL(8, 96, 14),
QT_MOC_LITERAL(9, 111, 15)
    },
    "tNotesTitleBar\0minimizeWindow\0\0"
    "maxmizeRestoreWindow\0closeWindow\0"
    "moveStart\0moveEnd\0showMinimized\0"
    "showMaxRestore\0closeMainWindow\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tNotesTitleBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06,
       3,    1,   55,    2, 0x06,
       4,    0,   58,    2, 0x06,
       5,    1,   59,    2, 0x06,
       6,    1,   62,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   65,    2, 0x08,
       8,    0,   66,    2, 0x08,
       9,    0,   67,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void tNotesTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tNotesTitleBar *_t = static_cast<tNotesTitleBar *>(_o);
        switch (_id) {
        case 0: _t->minimizeWindow(); break;
        case 1: _t->maxmizeRestoreWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->closeWindow(); break;
        case 3: _t->moveStart((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->moveEnd((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->showMinimized(); break;
        case 6: _t->showMaxRestore(); break;
        case 7: _t->closeMainWindow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (tNotesTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesTitleBar::minimizeWindow)) {
                *result = 0;
            }
        }
        {
            typedef void (tNotesTitleBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesTitleBar::maxmizeRestoreWindow)) {
                *result = 1;
            }
        }
        {
            typedef void (tNotesTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesTitleBar::closeWindow)) {
                *result = 2;
            }
        }
        {
            typedef void (tNotesTitleBar::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesTitleBar::moveStart)) {
                *result = 3;
            }
        }
        {
            typedef void (tNotesTitleBar::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesTitleBar::moveEnd)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject tNotesTitleBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tNotesTitleBar.data,
      qt_meta_data_tNotesTitleBar,  qt_static_metacall, 0, 0}
};


const QMetaObject *tNotesTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tNotesTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tNotesTitleBar.stringdata))
        return static_cast<void*>(const_cast< tNotesTitleBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int tNotesTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void tNotesTitleBar::minimizeWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void tNotesTitleBar::maxmizeRestoreWindow(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void tNotesTitleBar::closeWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void tNotesTitleBar::moveStart(QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void tNotesTitleBar::moveEnd(QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
