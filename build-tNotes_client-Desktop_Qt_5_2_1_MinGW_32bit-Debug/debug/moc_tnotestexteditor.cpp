/****************************************************************************
** Meta object code from reading C++ file 'tnotestexteditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/tnotestexteditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tnotestexteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tNotesTextEditor_t {
    QByteArrayData data[5];
    char stringdata[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_tNotesTextEditor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_tNotesTextEditor_t qt_meta_stringdata_tNotesTextEditor = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 14),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 7),
QT_MOC_LITERAL(4, 41, 9)
    },
    "tNotesTextEditor\0editModeChange\0\0"
    "setBold\0setItalic\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tNotesTextEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08,
       3,    0,   30,    2, 0x08,
       4,    0,   31,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void tNotesTextEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tNotesTextEditor *_t = static_cast<tNotesTextEditor *>(_o);
        switch (_id) {
        case 0: _t->editModeChange(); break;
        case 1: _t->setBold(); break;
        case 2: _t->setItalic(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject tNotesTextEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tNotesTextEditor.data,
      qt_meta_data_tNotesTextEditor,  qt_static_metacall, 0, 0}
};


const QMetaObject *tNotesTextEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tNotesTextEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tNotesTextEditor.stringdata))
        return static_cast<void*>(const_cast< tNotesTextEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int tNotesTextEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
