INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/qqmlandroidr_p.h \
    $$PWD/qtqmlandroidmodule_p.h

SOURCES += \
    $$PWD/qqmlandroidr.cpp \
    $$PWD/qtqmlandroidmodule.cpp

include(app/app.pri)
include(core/core.pri)
include(content/content.pri)
include(graphics/graphics.pri)
include(support/support.pri)
include(view/view.pri)
include(widget/widget.pri)
