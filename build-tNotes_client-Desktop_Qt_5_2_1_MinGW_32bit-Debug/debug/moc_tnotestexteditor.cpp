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
    QByteArrayData data[17];
    char stringdata[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_tNotesTextEditor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_tNotesTextEditor_t qt_meta_stringdata_tNotesTextEditor = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 10),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 6),
QT_MOC_LITERAL(4, 36, 5),
QT_MOC_LITERAL(5, 42, 9),
QT_MOC_LITERAL(6, 52, 18),
QT_MOC_LITERAL(7, 71, 14),
QT_MOC_LITERAL(8, 86, 7),
QT_MOC_LITERAL(9, 94, 9),
QT_MOC_LITERAL(10, 104, 7),
QT_MOC_LITERAL(11, 112, 8),
QT_MOC_LITERAL(12, 121, 14),
QT_MOC_LITERAL(13, 136, 7),
QT_MOC_LITERAL(14, 144, 17),
QT_MOC_LITERAL(15, 162, 13),
QT_MOC_LITERAL(16, 176, 11)
    },
    "tNotesTextEditor\0autoupdate\0\0string\0"
    "dirId\0articleId\0updateNoteFinished\0"
    "editModeChange\0setBold\0setItalic\0"
    "setCode\0setQuote\0openLinkDialog\0setLink\0"
    "slotUpdateArticle\0updateArticle\0"
    "initArticle\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tNotesTextEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06,
       6,    2,   79,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   84,    2, 0x08,
       8,    0,   85,    2, 0x08,
       9,    0,   86,    2, 0x08,
      10,    0,   87,    2, 0x08,
      11,    0,   88,    2, 0x08,
      12,    0,   89,    2, 0x08,
      13,    1,   90,    2, 0x08,
      14,    0,   93,    2, 0x08,
      15,    2,   94,    2, 0x08,
      16,    2,   99,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

       0        // eod
};

void tNotesTextEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tNotesTextEditor *_t = static_cast<tNotesTextEditor *>(_o);
        switch (_id) {
        case 0: _t->autoupdate((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 1: _t->updateNoteFinished((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 2: _t->editModeChange(); break;
        case 3: _t->setBold(); break;
        case 4: _t->setItalic(); break;
        case 5: _t->setCode(); break;
        case 6: _t->setQuote(); break;
        case 7: _t->openLinkDialog(); break;
        case 8: _t->setLink((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->slotUpdateArticle(); break;
        case 10: _t->updateArticle((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 11: _t->initArticle((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (tNotesTextEditor::*_t)(string , string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesTextEditor::autoupdate)) {
                *result = 0;
            }
        }
        {
            typedef void (tNotesTextEditor::*_t)(string , string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tNotesTextEditor::updateNoteFinished)) {
                *result = 1;
            }
        }
    }
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void tNotesTextEditor::autoupdate(string _t1, string _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tNotesTextEditor::updateNoteFinished(string _t1, string _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
