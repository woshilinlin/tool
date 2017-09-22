/****************************************************************************
** Meta object code from reading C++ file 'Label.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Label.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Label.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Label_t {
    QByteArrayData data[21];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_t qt_meta_stringdata_Label = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Label"
QT_MOC_LITERAL(1, 6, 7), // "xSignal"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 7), // "ySignal"
QT_MOC_LITERAL(4, 23, 7), // "horMove"
QT_MOC_LITERAL(5, 31, 7), // "verMove"
QT_MOC_LITERAL(6, 39, 9), // "pixSignal"
QT_MOC_LITERAL(7, 49, 11), // "wheelSignal"
QT_MOC_LITERAL(8, 61, 11), // "pressPionts"
QT_MOC_LITERAL(9, 73, 8), // "newPoint"
QT_MOC_LITERAL(10, 82, 10), // "showPixmap"
QT_MOC_LITERAL(11, 93, 6), // "pixMap"
QT_MOC_LITERAL(12, 100, 8), // "filePath"
QT_MOC_LITERAL(13, 109, 11), // "removePoint"
QT_MOC_LITERAL(14, 121, 3), // "row"
QT_MOC_LITERAL(15, 125, 4), // "test"
QT_MOC_LITERAL(16, 130, 9), // "longPress"
QT_MOC_LITERAL(17, 140, 15), // "setCameraPixmap"
QT_MOC_LITERAL(18, 156, 12), // "receiveImage"
QT_MOC_LITERAL(19, 169, 6), // "images"
QT_MOC_LITERAL(20, 176, 7) // "timeOut"

    },
    "Label\0xSignal\0\0ySignal\0horMove\0verMove\0"
    "pixSignal\0wheelSignal\0pressPionts\0"
    "newPoint\0showPixmap\0pixMap\0filePath\0"
    "removePoint\0row\0test\0longPress\0"
    "setCameraPixmap\0receiveImage\0images\0"
    "timeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    2,   97,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       5,    1,  105,    2, 0x06 /* Public */,
       6,    0,  108,    2, 0x06 /* Public */,
       7,    0,  109,    2, 0x06 /* Public */,
       8,    1,  110,    2, 0x06 /* Public */,
       9,    1,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  116,    2, 0x0a /* Public */,
      10,    1,  119,    2, 0x0a /* Public */,
      13,    1,  122,    2, 0x0a /* Public */,
      15,    0,  125,    2, 0x08 /* Private */,
      16,    0,  126,    2, 0x08 /* Private */,
      17,    0,  127,    2, 0x08 /* Private */,
      18,    1,  128,    2, 0x08 /* Private */,
      20,    0,  131,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QPixmap,   11,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,   19,
    QMetaType::Void,

       0        // eod
};

void Label::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label *_t = static_cast<Label *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xSignal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->ySignal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->horMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->verMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->pixSignal(); break;
        case 5: _t->wheelSignal(); break;
        case 6: _t->pressPionts((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->newPoint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->showPixmap((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 9: _t->showPixmap((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->removePoint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->test(); break;
        case 12: _t->longPress(); break;
        case 13: _t->setCameraPixmap(); break;
        case 14: _t->receiveImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 15: _t->timeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Label::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Label::xSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Label::*_t)(double , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Label::ySignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Label::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Label::horMove)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Label::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Label::verMove)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Label::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Label::pixSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Label::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Label::wheelSignal)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Label::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Label::pressPionts)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Label::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Label::newPoint)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject Label::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_Label.data,
      qt_meta_data_Label,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Label::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Label.stringdata0))
        return static_cast<void*>(const_cast< Label*>(this));
    return QLabel::qt_metacast(_clname);
}

int Label::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void Label::xSignal(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Label::ySignal(double _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Label::horMove(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Label::verMove(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Label::pixSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Label::wheelSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Label::pressPionts(QPoint _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Label::newPoint(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
