CONFIG -= qt android_install

OTHER_FILES += \
    $$PWD/qt/android/app/QtActivity.java \
    $$PWD/qt/android/app/QtService.java \
    $$PWD/qt/android/support/v4/widget/QtSwipeRefreshLayoutListener.java \
    $$PWD/qt/android/support/v7/widget/QtRecyclerAdapter.java \
    $$PWD/qt/android/view/QtMenu.java \
    $$PWD/qt/android/view/QtMenuItem.java \
    $$PWD/qt/android/view/QtViewListener.java \
    $$PWD/qt/android/widget/QtCompoundButtonListener.java \
    $$PWD/qt/android/widget/QtNumberPickerListener.java \
    $$PWD/qt/android/widget/QtRadioGroupListener.java \
    $$PWD/qt/android/widget/QtRatingBarListener.java \
    $$PWD/qt/android/widget/QtScrollView.java \
    $$PWD/qt/android/widget/QtSeekBarListener.java \
    $$PWD/qt/android/widget/QtTabHostListener.java

java.files = $$PWD/qt
java.path = $$[QT_INSTALL_PREFIX]/src/java
INSTALLS += java

contains(QT_CONFIG, private_tests) {   # -developer-build
    QMAKE_POST_LINK += \
        $${QMAKE_COPY_DIR} $$shell_path($$PWD/qt) $$shell_path($$java.path)
}
