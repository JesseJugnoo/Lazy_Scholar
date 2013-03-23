/****************************************************************************
** Meta object code from reading C++ file 'Paint.hpp'
**
** Created: Sat Mar 23 17:09:21 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Paint.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Paint.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Paint[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       4,   69, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      22,    6,    6,    6, 0x05,
      41,    6,    6,    6, 0x05,
      60,    6,    6,    6, 0x05,

 // methods: signature, parameters, type, tag, flags
      85,   76,    6,    6, 0x02,
     111,  107,    6,    6, 0x02,
     134,  107,    6,    6, 0x02,
     158,  152,    6,    6, 0x02,
     186,    6,  181,    6, 0x02,
     213,  199,    6,    6, 0x02,
     247,  238,    6,    6, 0x02,

 // properties: name, type, flags
     294,  274, 0x00495009,
     308,  300, 0x0a495001,
     320,  274, 0x00495009,
     330,  274, 0x00495009,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

static const char qt_meta_stringdata_Paint[] = {
    "Paint\0\0imageChanged()\0translateChanged()\0"
    "textImageChanged()\0ratingChanged()\0"
    "language\0setLanguage(QVariant)\0x,y\0"
    "startDraw(float,float)\0draw(float,float)\0"
    "level\0initDrawPage(QVariant)\0bool\0"
    "finishDraw()\0selectedIndex\0"
    "setCharacterByIndex(int)\0addIndex\0"
    "navigateNextCharacter(int)\0"
    "bb::cascades::Image\0image\0QString\0"
    "translation\0textImage\0rating\0"
};

void Paint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Paint *_t = static_cast<Paint *>(_o);
        switch (_id) {
        case 0: _t->imageChanged(); break;
        case 1: _t->translateChanged(); break;
        case 2: _t->textImageChanged(); break;
        case 3: _t->ratingChanged(); break;
        case 4: _t->setLanguage((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 5: _t->startDraw((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 6: _t->draw((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 7: _t->initDrawPage((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 8: { bool _r = _t->finishDraw();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->setCharacterByIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->navigateNextCharacter((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Paint::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Paint::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Paint,
      qt_meta_data_Paint, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Paint::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Paint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Paint::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Paint))
        return static_cast<void*>(const_cast< Paint*>(this));
    return QObject::qt_metacast(_clname);
}

int Paint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bb::cascades::Image*>(_v) = image(); break;
        case 1: *reinterpret_cast< QString*>(_v) = translation(); break;
        case 2: *reinterpret_cast< bb::cascades::Image*>(_v) = textImage(); break;
        case 3: *reinterpret_cast< bb::cascades::Image*>(_v) = rating(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Paint::imageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Paint::translateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Paint::textImageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Paint::ratingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
