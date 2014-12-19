INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/qtqmlandroidgravity_p.h \
    $$PWD/qtqmlandroidlayoutparams_p.h \
    $$PWD/qtqmlandroidmenu_p.h \
    $$PWD/qtqmlandroidmenuitem_p.h \
    $$PWD/qtqmlandroidview_p.h \
    $$PWD/qtqmlandroidviewgroup_p.h \
    $$PWD/qtqmlandroidviewmodule_p.h \
    $$PWD/qtqmlandroidwindow_p.h

SOURCES += \
    $$PWD/qtqmlandroidlayoutparams.cpp \
    $$PWD/qtqmlandroidmenu.cpp \
    $$PWD/qtqmlandroidmenuitem.cpp \
    $$PWD/qtqmlandroidview.cpp \
    $$PWD/qtqmlandroidviewgroup.cpp \
    $$PWD/qtqmlandroidviewmodule.cpp \
    $$PWD/qtqmlandroidwindow.cpp

include(animation/animation.pri)
