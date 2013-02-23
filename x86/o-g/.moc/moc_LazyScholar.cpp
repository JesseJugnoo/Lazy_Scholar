/****************************************************************************
** Meta object code from reading C++ file 'LazyScholar.hpp'
**
** Created: Sat Feb 23 13:27:16 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/LazyScholar.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LazyScholar.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LazyScholar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      29,   12,   12,   12, 0x05,

 // methods: signature, parameters, type, tag, flags
      44,   12,   12,   12, 0x02,
      61,   57,   12,   12, 0x02,
      87,   57,   12,   12, 0x02,

 // properties: name, type, flags
     120,  112, 0x0a495103,
     147,  127, 0x00495009,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_LazyScholar[] = {
    "LazyScholar\0\0objectChanged()\0"
    "imageChanged()\0paintImage()\0x,y\0"
    "setLastPoint(float,float)\0"
    "setEndPoint(float,float)\0QString\0"
    "object\0bb::cascades::Image\0image\0"
};

void LazyScholar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LazyScholar *_t = static_cast<LazyScholar *>(_o);
        switch (_id) {
        case 0: _t->objectChanged(); break;
        case 1: _t->imageChanged(); break;
        case 2: _t->paintImage(); break;
        case 3: _t->setLastPoint((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 4: _t->setEndPoint((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LazyScholar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LazyScholar::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LazyScholar,
      qt_meta_data_LazyScholar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LazyScholar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LazyScholar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LazyScholar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LazyScholar))
        return static_cast<void*>(const_cast< LazyScholar*>(this));
    return QObject::qt_metacast(_clname);
}

int LazyScholar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = object(); break;
        case 1: *reinterpret_cast< bb::cascades::Image*>(_v) = image(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setObject(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void LazyScholar::objectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void LazyScholar::imageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
