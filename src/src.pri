ANDROID_PACKAGE_SOURCE_DIR = $$PWD/java

OTHER_FILES += \
    $$PWD/java/AndroidManifest.xml \
    $$PWD/java/src/qtdroid/view/QtViewListener.java \
    $$PWD/java/src/qtdroid/widget/QtCompoundButtonListener.java \
    $$PWD/java/src/qtdroid/widget/QtSeekBarListener.java

include(app/app.pri)
include(core/core.pri)
include(content/content.pri)
include(support/support.pri)
include(view/view.pri)
include(widget/widget.pri)
