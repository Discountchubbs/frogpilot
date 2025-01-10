/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SettingsWindow_t {
    QByteArrayData data[13];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsWindow_t qt_meta_stringdata_SettingsWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SettingsWindow"
QT_MOC_LITERAL(1, 15, 13), // "closeSettings"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "reviewTrainingGuide"
QT_MOC_LITERAL(4, 50, 14), // "showDriverView"
QT_MOC_LITERAL(5, 65, 23), // "expandToggleDescription"
QT_MOC_LITERAL(6, 89, 5), // "param"
QT_MOC_LITERAL(7, 95, 23), // "closeMapBoxInstructions"
QT_MOC_LITERAL(8, 119, 17), // "closeMapSelection"
QT_MOC_LITERAL(9, 137, 10), // "closePanel"
QT_MOC_LITERAL(10, 148, 17), // "closeParentToggle"
QT_MOC_LITERAL(11, 166, 20), // "closeSubParentToggle"
QT_MOC_LITERAL(12, 187, 12) // "updateMetric"

    },
    "SettingsWindow\0closeSettings\0\0"
    "reviewTrainingGuide\0showDriverView\0"
    "expandToggleDescription\0param\0"
    "closeMapBoxInstructions\0closeMapSelection\0"
    "closePanel\0closeParentToggle\0"
    "closeSubParentToggle\0updateMetric"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       7,    0,   70,    2, 0x06 /* Public */,
       8,    0,   71,    2, 0x06 /* Public */,
       9,    0,   72,    2, 0x06 /* Public */,
      10,    0,   73,    2, 0x06 /* Public */,
      11,    0,   74,    2, 0x06 /* Public */,
      12,    0,   75,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeSettings(); break;
        case 1: _t->reviewTrainingGuide(); break;
        case 2: _t->showDriverView(); break;
        case 3: _t->expandToggleDescription((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->closeMapBoxInstructions(); break;
        case 5: _t->closeMapSelection(); break;
        case 6: _t->closePanel(); break;
        case 7: _t->closeParentToggle(); break;
        case 8: _t->closeSubParentToggle(); break;
        case 9: _t->updateMetric(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::closeSettings)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::reviewTrainingGuide)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::showDriverView)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SettingsWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::expandToggleDescription)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::closeMapBoxInstructions)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::closeMapSelection)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::closePanel)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::closeParentToggle)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::closeSubParentToggle)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (SettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::updateMetric)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SettingsWindow::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_SettingsWindow.data,
    qt_meta_data_SettingsWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsWindow.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int SettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SettingsWindow::closeSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SettingsWindow::reviewTrainingGuide()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SettingsWindow::showDriverView()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SettingsWindow::expandToggleDescription(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SettingsWindow::closeMapBoxInstructions()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SettingsWindow::closeMapSelection()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SettingsWindow::closePanel()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void SettingsWindow::closeParentToggle()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void SettingsWindow::closeSubParentToggle()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void SettingsWindow::updateMetric()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
struct qt_meta_stringdata_DevicePanel_t {
    QByteArrayData data[7];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DevicePanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DevicePanel_t qt_meta_stringdata_DevicePanel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DevicePanel"
QT_MOC_LITERAL(1, 12, 19), // "reviewTrainingGuide"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "showDriverView"
QT_MOC_LITERAL(4, 48, 8), // "poweroff"
QT_MOC_LITERAL(5, 57, 6), // "reboot"
QT_MOC_LITERAL(6, 64, 22) // "updateCalibDescription"

    },
    "DevicePanel\0reviewTrainingGuide\0\0"
    "showDriverView\0poweroff\0reboot\0"
    "updateCalibDescription"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DevicePanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DevicePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DevicePanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reviewTrainingGuide(); break;
        case 1: _t->showDriverView(); break;
        case 2: _t->poweroff(); break;
        case 3: _t->reboot(); break;
        case 4: _t->updateCalibDescription(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DevicePanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DevicePanel::reviewTrainingGuide)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DevicePanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DevicePanel::showDriverView)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DevicePanel::staticMetaObject = { {
    &ListWidget::staticMetaObject,
    qt_meta_stringdata_DevicePanel.data,
    qt_meta_data_DevicePanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DevicePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DevicePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DevicePanel.stringdata0))
        return static_cast<void*>(this);
    return ListWidget::qt_metacast(_clname);
}

int DevicePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ListWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void DevicePanel::reviewTrainingGuide()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DevicePanel::showDriverView()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_TogglesPanel_t {
    QByteArrayData data[8];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TogglesPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TogglesPanel_t qt_meta_stringdata_TogglesPanel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TogglesPanel"
QT_MOC_LITERAL(1, 13, 12), // "updateMetric"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 23), // "expandToggleDescription"
QT_MOC_LITERAL(4, 51, 5), // "param"
QT_MOC_LITERAL(5, 57, 11), // "updateState"
QT_MOC_LITERAL(6, 69, 7), // "UIState"
QT_MOC_LITERAL(7, 77, 1) // "s"

    },
    "TogglesPanel\0updateMetric\0\0"
    "expandToggleDescription\0param\0updateState\0"
    "UIState\0s"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TogglesPanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x0a /* Public */,
       5,    1,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void TogglesPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TogglesPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMetric(); break;
        case 1: _t->expandToggleDescription((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->updateState((*reinterpret_cast< const UIState(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TogglesPanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TogglesPanel::updateMetric)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TogglesPanel::staticMetaObject = { {
    &ListWidget::staticMetaObject,
    qt_meta_stringdata_TogglesPanel.data,
    qt_meta_data_TogglesPanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TogglesPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TogglesPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TogglesPanel.stringdata0))
        return static_cast<void*>(this);
    return ListWidget::qt_metacast(_clname);
}

int TogglesPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void TogglesPanel::updateMetric()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_SoftwarePanel_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SoftwarePanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SoftwarePanel_t qt_meta_stringdata_SoftwarePanel = {
    {
QT_MOC_LITERAL(0, 0, 13) // "SoftwarePanel"

    },
    "SoftwarePanel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoftwarePanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SoftwarePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SoftwarePanel::staticMetaObject = { {
    &ListWidget::staticMetaObject,
    qt_meta_stringdata_SoftwarePanel.data,
    qt_meta_data_SoftwarePanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SoftwarePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoftwarePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SoftwarePanel.stringdata0))
        return static_cast<void*>(this);
    return ListWidget::qt_metacast(_clname);
}

int SoftwarePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ListWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
