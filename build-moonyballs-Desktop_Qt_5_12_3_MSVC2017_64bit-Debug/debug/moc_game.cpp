/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Demo/game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Game_t {
    QByteArrayData data[21];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Game_t qt_meta_stringdata_Game = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Game"
QT_MOC_LITERAL(1, 5, 8), // "tryagain"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 13), // "getDifficulty"
QT_MOC_LITERAL(4, 29, 10), // "difficulty"
QT_MOC_LITERAL(5, 40, 13), // "setDifficulty"
QT_MOC_LITERAL(6, 54, 8), // "gamePlay"
QT_MOC_LITERAL(7, 63, 22), // "on_TestFailure_clicked"
QT_MOC_LITERAL(8, 86, 9), // "closeself"
QT_MOC_LITERAL(9, 96, 11), // "chooseagain"
QT_MOC_LITERAL(10, 108, 15), // "generateNewBall"
QT_MOC_LITERAL(11, 124, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(12, 148, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(13, 172, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(14, 196, 16), // "on_pause_clicked"
QT_MOC_LITERAL(15, 213, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(16, 237, 7), // "uplevel"
QT_MOC_LITERAL(17, 245, 8), // "geneBars"
QT_MOC_LITERAL(18, 254, 9), // "geneProps"
QT_MOC_LITERAL(19, 264, 10), // "resumeGame"
QT_MOC_LITERAL(20, 275, 14) // "on_Buy_clicked"

    },
    "Game\0tryagain\0\0getDifficulty\0difficulty\0"
    "setDifficulty\0gamePlay\0on_TestFailure_clicked\0"
    "closeself\0chooseagain\0generateNewBall\0"
    "on_pushButton_2_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_3_clicked\0on_pause_clicked\0"
    "on_pushButton_5_clicked\0uplevel\0"
    "geneBars\0geneProps\0resumeGame\0"
    "on_Buy_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  105,    2, 0x08 /* Private */,
       5,    1,  108,    2, 0x08 /* Private */,
       6,    0,  111,    2, 0x08 /* Private */,
       7,    0,  112,    2, 0x08 /* Private */,
       8,    0,  113,    2, 0x08 /* Private */,
       9,    0,  114,    2, 0x08 /* Private */,
      10,    0,  115,    2, 0x08 /* Private */,
      11,    0,  116,    2, 0x08 /* Private */,
      12,    0,  117,    2, 0x08 /* Private */,
      13,    0,  118,    2, 0x08 /* Private */,
      14,    0,  119,    2, 0x08 /* Private */,
      15,    0,  120,    2, 0x08 /* Private */,
      16,    0,  121,    2, 0x08 /* Private */,
      17,    0,  122,    2, 0x08 /* Private */,
      18,    0,  123,    2, 0x08 /* Private */,
      19,    0,  124,    2, 0x08 /* Private */,
      20,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Char,    4,
    QMetaType::Void, QMetaType::Char,    4,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tryagain(); break;
        case 1: _t->getDifficulty((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 2: _t->setDifficulty((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 3: _t->gamePlay(); break;
        case 4: _t->on_TestFailure_clicked(); break;
        case 5: _t->closeself(); break;
        case 6: _t->chooseagain(); break;
        case 7: _t->generateNewBall(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->on_pushButton_4_clicked(); break;
        case 10: _t->on_pushButton_3_clicked(); break;
        case 11: _t->on_pause_clicked(); break;
        case 12: _t->on_pushButton_5_clicked(); break;
        case 13: _t->uplevel(); break;
        case 14: _t->geneBars(); break;
        case 15: _t->geneProps(); break;
        case 16: _t->resumeGame(); break;
        case 17: _t->on_Buy_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Game::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::tryagain)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Game::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Game.data,
    qt_meta_data_Game,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Game.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Game::tryagain()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
