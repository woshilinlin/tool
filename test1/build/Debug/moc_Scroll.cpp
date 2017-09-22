/****************************************************************************
** Meta object code from reading C++ file 'Scroll.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Scroll.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Scroll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Scroll_t {
    QByteArrayData data[11];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scroll_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scroll_t qt_meta_stringdata_Scroll = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Scroll"
QT_MOC_LITERAL(1, 7, 11), // "getHorValue"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 1), // "x"
QT_MOC_LITERAL(4, 22, 11), // "getVerValue"
QT_MOC_LITERAL(5, 34, 1), // "y"
QT_MOC_LITERAL(6, 36, 11), // "setHorValue"
QT_MOC_LITERAL(7, 48, 11), // "setVerValue"
QT_MOC_LITERAL(8, 60, 5), // "delta"
QT_MOC_LITERAL(9, 66, 8), // "setValue"
QT_MOC_LITERAL(10, 75, 5) // "point"

    },
    "Scroll\0getHorValue\0\0x\0getVerValue\0y\0"
    "setHorValue\0setVerValue\0delta\0setValue\0"
    "point"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scroll[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       6,    1,   45,    2, 0x0a /* Public */,
       7,    2,   48,    2, 0x0a /* Public */,
       9,    1,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double, QMetaType::Int,    5,    8,
    QMetaType::Void, QMetaType::QPoint,   10,

       0        // eod
};

void Scroll::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Scroll *_t = static_cast<Scroll *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getHorValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->getVerValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setHorValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setVerValue((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->setValue((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Scroll::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_Scroll.data,
      qt_meta_data_Scroll,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Scroll::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scroll::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Scroll.stringdata0))
        return static_cast<void*>(const_cast< Scroll*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int Scroll::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
