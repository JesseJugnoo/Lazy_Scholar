/****************************************************************************
** Meta object code from reading C++ file 'Quiz.hpp'
**
** Created: Thu Mar 28 12:49:56 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Quiz.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Quiz.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Quiz[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       6,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,

 // methods: signature, parameters, type, tag, flags
      21,    5,    5,    5, 0x02,
      48,    5,   40,    5, 0x02,
      61,    5,   40,    5, 0x02,
      73,    5,   40,    5, 0x02,
      85,    5,   40,    5, 0x02,
      97,    5,   40,    5, 0x02,
     109,    5,   40,    5, 0x02,

 // properties: name, type, flags
     127,   40, 0x0a495001,
     137,   40, 0x0a495001,
     147,   40, 0x0a495001,
     157,   40, 0x0a495001,
     167,   40, 0x0a495001,
     178,   40, 0x0a495001,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_Quiz[] = {
    "Quiz\0\0valueChanged()\0loadTheQuestions()\0"
    "QString\0getCorrect()\0getGuess1()\0"
    "getGuess2()\0getGuess3()\0getGuess4()\0"
    "getToBeAnswered()\0getGuess1\0getGuess2\0"
    "getGuess3\0getGuess4\0getCorrect\0"
    "getToBeAnswered\0"
};

void Quiz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Quiz *_t = static_cast<Quiz *>(_o);
        switch (_id) {
        case 0: _t->valueChanged(); break;
        case 1: _t->loadTheQuestions(); break;
        case 2: { QString _r = _t->getCorrect();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { QString _r = _t->getGuess1();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->getGuess2();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->getGuess3();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { QString _r = _t->getGuess4();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->getToBeAnswered();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Quiz::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Quiz::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Quiz,
      qt_meta_data_Quiz, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Quiz::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Quiz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Quiz::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Quiz))
        return static_cast<void*>(const_cast< Quiz*>(this));
    return QObject::qt_metacast(_clname);
}

int Quiz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getGuess1(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getGuess2(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getGuess3(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getGuess4(); break;
        case 4: *reinterpret_cast< QString*>(_v) = getCorrect(); break;
        case 5: *reinterpret_cast< QString*>(_v) = getToBeAnswered(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Quiz::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
