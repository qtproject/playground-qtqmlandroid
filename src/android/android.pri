INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/qtandroidmodule_p.h \
    $$PWD/qtandroidr_p.h

SOURCES += \
    $$PWD/qtandroidmodule.cpp \
    $$PWD/qtandroidr.cpp

include(app/app.pri)
include(core/core.pri)
include(content/content.pri)
include(graphics/graphics.pri)
include(java/java.pri)
include(support/support.pri)
include(view/view.pri)
include(widget/widget.pri)
