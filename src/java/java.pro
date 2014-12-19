CONFIG -= qt android_install

OTHER_FILES += \
    $$PWD/src/qt/android/app/QtActivity.java \
    $$PWD/src/qt/android/app/QtService.java \
    $$PWD/src/qt/android/support/v4/widget/QtSwipeRefreshLayoutListener.java \
    $$PWD/src/qt/android/support/v7/widget/QtRecyclerAdapter.java \
    $$PWD/src/qt/android/view/QtMenu.java \
    $$PWD/src/qt/android/view/QtMenuItem.java \
    $$PWD/src/qt/android/view/QtViewListener.java \
    $$PWD/src/qt/android/widget/QtCompoundButtonListener.java \
    $$PWD/src/qt/android/widget/QtNumberPickerListener.java \
    $$PWD/src/qt/android/widget/QtRadioGroupListener.java \
    $$PWD/src/qt/android/widget/QtRatingBarListener.java \
    $$PWD/src/qt/android/widget/QtScrollView.java \
    $$PWD/src/qt/android/widget/QtSeekBarListener.java \
    $$PWD/src/qt/android/widget/QtTabHostListener.java

javaresources.files = $$PWD/src
javaresources.path = $$[QT_INSTALL_PREFIX]/src/android/java

INSTALLS += javaresources

!prefix_build:!equals(OUT_PWD, $$PWD) {
    RETURN = $$escape_expand(\\n\\t)
    equals(QMAKE_HOST.os, Windows) {
        RETURN = $$escape_expand(\\r\\n\\t)
    }
    OUT_PATH = $$shell_path($$OUT_PWD)

    QMAKE_POST_LINK += \
        $${QMAKE_COPY_DIR} $$shell_path($$PWD/src) $$OUT_PATH
}
