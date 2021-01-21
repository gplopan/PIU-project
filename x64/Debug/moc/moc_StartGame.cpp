/****************************************************************************
** Meta object code from reading C++ file 'StartGame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../headers/StartGame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StartGame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StartGame_t {
    QByteArrayData data[13];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StartGame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StartGame_t qt_meta_stringdata_StartGame = {
    {
QT_MOC_LITERAL(0, 0, 9), // "StartGame"
QT_MOC_LITERAL(1, 10, 14), // "emitToAddTower"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 1), // "x"
QT_MOC_LITERAL(4, 28, 1), // "y"
QT_MOC_LITERAL(5, 30, 17), // "emitToRotateTower"
QT_MOC_LITERAL(6, 48, 15), // "emitTurnToEnemy"
QT_MOC_LITERAL(7, 64, 16), // "drawEnemyInScene"
QT_MOC_LITERAL(8, 81, 7), // "getTile"
QT_MOC_LITERAL(9, 89, 4), // "int*"
QT_MOC_LITERAL(10, 94, 4), // "tile"
QT_MOC_LITERAL(11, 99, 12), // "generateWave"
QT_MOC_LITERAL(12, 112, 4) // "wait"

    },
    "StartGame\0emitToAddTower\0\0x\0y\0"
    "emitToRotateTower\0emitTurnToEnemy\0"
    "drawEnemyInScene\0getTile\0int*\0tile\0"
    "generateWave\0wait"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StartGame[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    2,   54,    2, 0x06 /* Public */,
       6,    2,   59,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,   65,    2, 0x0a /* Public */,
      11,    0,   72,    2, 0x0a /* Public */,
      12,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int, QMetaType::Int,   10,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StartGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StartGame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emitToAddTower((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->emitToRotateTower((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->emitTurnToEnemy((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->drawEnemyInScene(); break;
        case 4: _t->getTile((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->generateWave(); break;
        case 6: _t->wait(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StartGame::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StartGame::emitToAddTower)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StartGame::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StartGame::emitToRotateTower)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (StartGame::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StartGame::emitTurnToEnemy)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (StartGame::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StartGame::drawEnemyInScene)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StartGame::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_StartGame.data,
    qt_meta_data_StartGame,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StartGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StartGame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StartGame.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StartGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void StartGame::emitToAddTower(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StartGame::emitToRotateTower(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StartGame::emitTurnToEnemy(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void StartGame::drawEnemyInScene()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
