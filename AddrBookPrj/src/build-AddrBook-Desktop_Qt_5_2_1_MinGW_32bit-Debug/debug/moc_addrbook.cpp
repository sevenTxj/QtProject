/****************************************************************************
** Meta object code from reading C++ file 'addrbook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AddrBook/addrbook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addrbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddrBook_t {
    QByteArrayData data[12];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AddrBook_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AddrBook_t qt_meta_stringdata_AddrBook = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 10),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 13),
QT_MOC_LITERAL(4, 35, 6),
QT_MOC_LITERAL(5, 42, 4),
QT_MOC_LITERAL(6, 47, 8),
QT_MOC_LITERAL(7, 56, 11),
QT_MOC_LITERAL(8, 68, 13),
QT_MOC_LITERAL(9, 82, 10),
QT_MOC_LITERAL(10, 93, 12),
QT_MOC_LITERAL(11, 106, 11)
    },
    "AddrBook\0addContact\0\0submitContact\0"
    "cancel\0next\0previous\0editContact\0"
    "removeContact\0saveToFile\0loadFromFile\0"
    "findContact\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddrBook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a,
       3,    0,   65,    2, 0x0a,
       4,    0,   66,    2, 0x0a,
       5,    0,   67,    2, 0x0a,
       6,    0,   68,    2, 0x0a,
       7,    0,   69,    2, 0x0a,
       8,    0,   70,    2, 0x0a,
       9,    0,   71,    2, 0x0a,
      10,    0,   72,    2, 0x0a,
      11,    0,   73,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddrBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddrBook *_t = static_cast<AddrBook *>(_o);
        switch (_id) {
        case 0: _t->addContact(); break;
        case 1: _t->submitContact(); break;
        case 2: _t->cancel(); break;
        case 3: _t->next(); break;
        case 4: _t->previous(); break;
        case 5: _t->editContact(); break;
        case 6: _t->removeContact(); break;
        case 7: _t->saveToFile(); break;
        case 8: _t->loadFromFile(); break;
        case 9: _t->findContact(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AddrBook::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddrBook.data,
      qt_meta_data_AddrBook,  qt_static_metacall, 0, 0}
};


const QMetaObject *AddrBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddrBook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddrBook.stringdata))
        return static_cast<void*>(const_cast< AddrBook*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddrBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
