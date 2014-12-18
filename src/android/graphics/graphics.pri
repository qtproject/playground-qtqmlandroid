INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/qtandroidcolor_p.h \
    $$PWD/qtandroidgraphicsmodule_p.h

SOURCES += \
    $$PWD/qtandroidcolor.cpp \
    $$PWD/qtandroidgraphicsmodule.cpp

include(drawable/drawable.pri)
