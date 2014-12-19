INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/qqmlandroidgravity_p.h \
    $$PWD/qqmlandroidlayoutparams_p.h \
    $$PWD/qqmlandroidmenu_p.h \
    $$PWD/qqmlandroidmenuitem_p.h \
    $$PWD/qqmlandroidview_p.h \
    $$PWD/qqmlandroidviewgroup_p.h \
    $$PWD/qqmlandroidwindow_p.h \
    $$PWD/qtqmlandroidviewmodule_p.h

SOURCES += \
    $$PWD/qqmlandroidlayoutparams.cpp \
    $$PWD/qqmlandroidmenu.cpp \
    $$PWD/qqmlandroidmenuitem.cpp \
    $$PWD/qqmlandroidview.cpp \
    $$PWD/qqmlandroidviewgroup.cpp \
    $$PWD/qqmlandroidwindow.cpp \
    $$PWD/qtqmlandroidviewmodule.cpp

include(animation/animation.pri)
