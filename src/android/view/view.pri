INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/qnativeandroidgravity_p.h \
    $$PWD/qnativeandroidlayoutparams_p.h \
    $$PWD/qnativeandroidlayoutparams_p_p.h \
    $$PWD/qnativeandroidmenu_p.h \
    $$PWD/qnativeandroidmenu_p_p.h \
    $$PWD/qnativeandroidmenuitem_p.h \
    $$PWD/qnativeandroidview_p.h \
    $$PWD/qnativeandroidview_p_p.h \
    $$PWD/qnativeandroidviewgroup_p.h \
    $$PWD/qnativeandroidviewgroup_p_p.h \
    $$PWD/qnativeandroidwindow_p.h

SOURCES += \
    $$PWD/qnativeandroidlayoutparams.cpp \
    $$PWD/qnativeandroidmenu.cpp \
    $$PWD/qnativeandroidmenuitem.cpp \
    $$PWD/qnativeandroidview.cpp \
    $$PWD/qnativeandroidviewgroup.cpp \
    $$PWD/qnativeandroidwindow.cpp

include(animation/animation.pri)
