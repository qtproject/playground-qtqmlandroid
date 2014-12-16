INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/qtandroidgravity_p.h \
    $$PWD/qtandroidlayoutparams_p.h \
    $$PWD/qtandroidmenu_p.h \
    $$PWD/qtandroidmenuitem_p.h \
    $$PWD/qtandroidview_p.h \
    $$PWD/qtandroidviewgroup_p.h \
    $$PWD/qtandroidwindow_p.h

SOURCES += \
    $$PWD/qtandroidlayoutparams.cpp \
    $$PWD/qtandroidmenu.cpp \
    $$PWD/qtandroidmenuitem.cpp \
    $$PWD/qtandroidview.cpp \
    $$PWD/qtandroidviewgroup.cpp \
    $$PWD/qtandroidwindow.cpp

include(animation/animation.pri)
