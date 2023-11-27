/****************************************************************************
** Meta object code from reading C++ file 'settings_form.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/settings_form.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings_form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSettingsFormENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSettingsFormENDCLASS = QtMocHelpers::stringData(
    "SettingsForm",
    "save_changings",
    "",
    "discard_changings",
    "play_round_sound",
    "change_round_sound",
    "play_short_break_sound",
    "change_short_break_sound",
    "play_long_break_sound",
    "change_long_break_sound",
    "round_slider_changed",
    "short_slider_changed",
    "long_slider_changed",
    "pull_up_settings_changed"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSettingsFormENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[13];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[17];
    char stringdata5[19];
    char stringdata6[23];
    char stringdata7[25];
    char stringdata8[22];
    char stringdata9[24];
    char stringdata10[21];
    char stringdata11[21];
    char stringdata12[20];
    char stringdata13[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSettingsFormENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSettingsFormENDCLASS_t qt_meta_stringdata_CLASSSettingsFormENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "SettingsForm"
        QT_MOC_LITERAL(13, 14),  // "save_changings"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 17),  // "discard_changings"
        QT_MOC_LITERAL(47, 16),  // "play_round_sound"
        QT_MOC_LITERAL(64, 18),  // "change_round_sound"
        QT_MOC_LITERAL(83, 22),  // "play_short_break_sound"
        QT_MOC_LITERAL(106, 24),  // "change_short_break_sound"
        QT_MOC_LITERAL(131, 21),  // "play_long_break_sound"
        QT_MOC_LITERAL(153, 23),  // "change_long_break_sound"
        QT_MOC_LITERAL(177, 20),  // "round_slider_changed"
        QT_MOC_LITERAL(198, 20),  // "short_slider_changed"
        QT_MOC_LITERAL(219, 19),  // "long_slider_changed"
        QT_MOC_LITERAL(239, 24)   // "pull_up_settings_changed"
    },
    "SettingsForm",
    "save_changings",
    "",
    "discard_changings",
    "play_round_sound",
    "change_round_sound",
    "play_short_break_sound",
    "change_short_break_sound",
    "play_long_break_sound",
    "change_long_break_sound",
    "round_slider_changed",
    "short_slider_changed",
    "long_slider_changed",
    "pull_up_settings_changed"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSettingsFormENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x0a,    1 /* Public */,
       3,    0,   87,    2, 0x0a,    2 /* Public */,
       4,    0,   88,    2, 0x0a,    3 /* Public */,
       5,    0,   89,    2, 0x0a,    4 /* Public */,
       6,    0,   90,    2, 0x0a,    5 /* Public */,
       7,    0,   91,    2, 0x0a,    6 /* Public */,
       8,    0,   92,    2, 0x0a,    7 /* Public */,
       9,    0,   93,    2, 0x0a,    8 /* Public */,
      10,    1,   94,    2, 0x0a,    9 /* Public */,
      11,    1,   97,    2, 0x0a,   11 /* Public */,
      12,    1,  100,    2, 0x0a,   13 /* Public */,
      13,    1,  103,    2, 0x0a,   15 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject SettingsForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSSettingsFormENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSettingsFormENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSettingsFormENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SettingsForm, std::true_type>,
        // method 'save_changings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'discard_changings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'play_round_sound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'change_round_sound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'play_short_break_sound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'change_short_break_sound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'play_long_break_sound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'change_long_break_sound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'round_slider_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'short_slider_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'long_slider_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'pull_up_settings_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void SettingsForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->save_changings(); break;
        case 1: _t->discard_changings(); break;
        case 2: _t->play_round_sound(); break;
        case 3: _t->change_round_sound(); break;
        case 4: _t->play_short_break_sound(); break;
        case 5: _t->change_short_break_sound(); break;
        case 6: _t->play_long_break_sound(); break;
        case 7: _t->change_long_break_sound(); break;
        case 8: _t->round_slider_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->short_slider_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->long_slider_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->pull_up_settings_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *SettingsForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSettingsFormENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SettingsForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
