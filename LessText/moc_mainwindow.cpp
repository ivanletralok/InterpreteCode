/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      89,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     152,   11,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     218,   11,  213,   11, 0x08,
     246,   11,   11,   11, 0x08,
     271,   11,  213,   11, 0x08,
     297,   11,   11,   11, 0x08,
     323,   11,   11,   11, 0x08,
     349,   11,   11,   11, 0x08,
     388,  374,   11,   11, 0x08,
     430,  428,   11,   11, 0x08,
     467,  428,   11,   11, 0x08,
     504,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionQuit_triggered()\0"
    "on_actionCopy_triggered()\0"
    "on_actionCut_triggered()\0"
    "on_actionPaste_triggered()\0"
    "on_actionAboutQtCreator_triggered()\0"
    "on_actionAboutLessText_triggered()\0"
    "on_actionOpen_triggered()\0bool\0"
    "on_actionSaveAs_triggered()\0"
    "on_actionNew_triggered()\0"
    "on_actionSave_triggered()\0"
    "on_actionUndo_triggered()\0"
    "on_actionRedo_triggered()\0"
    "on_actionRun_triggered()\0newBlockCount\0"
    "on_plainTextEdit_blockCountChanged(int)\0"
    "b\0on_plainTextEdit_undoAvailable(bool)\0"
    "on_plainTextEdit_redoAvailable(bool)\0"
    "on_plainTextEdit_cursorPositionChanged()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionQuit_triggered(); break;
        case 1: _t->on_actionCopy_triggered(); break;
        case 2: _t->on_actionCut_triggered(); break;
        case 3: _t->on_actionPaste_triggered(); break;
        case 4: _t->on_actionAboutQtCreator_triggered(); break;
        case 5: _t->on_actionAboutLessText_triggered(); break;
        case 6: _t->on_actionOpen_triggered(); break;
        case 7: { bool _r = _t->on_actionSaveAs_triggered();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->on_actionNew_triggered(); break;
        case 9: { bool _r = _t->on_actionSave_triggered();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: _t->on_actionUndo_triggered(); break;
        case 11: _t->on_actionRedo_triggered(); break;
        case 12: _t->on_actionRun_triggered(); break;
        case 13: _t->on_plainTextEdit_blockCountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_plainTextEdit_undoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_plainTextEdit_redoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->on_plainTextEdit_cursorPositionChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
