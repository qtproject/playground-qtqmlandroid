INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/qtqmlandroidmodule_p.h \
    $$PWD/qtqmlandroidr_p.h

SOURCES += \
    $$PWD/qtqmlandroidmodule.cpp \
    $$PWD/qtqmlandroidr.cpp

include(app/app.pri)
include(core/core.pri)
include(content/content.pri)
include(graphics/graphics.pri)
include(support/support.pri)
include(view/view.pri)
include(widget/widget.pri)
