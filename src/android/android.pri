INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/qnativeandroidr_p.h
    $$PWD/qtnativeandroidglobal_p.h

SOURCES += \
    $$PWD/qnativeandroidr.cpp

include(app/app.pri)
include(core/core.pri)
include(content/content.pri)
include(graphics/graphics.pri)
include(support/support.pri)
include(view/view.pri)
include(widget/widget.pri)
