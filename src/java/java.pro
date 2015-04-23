CONFIG -= qt android_install

OTHER_FILES += \
    $$PWD/qt/android/app/QmlActivity.java \
    $$PWD/qt/android/app/QmlService.java \
    $$PWD/qt/android/support/v4/widget/QmlSwipeRefreshLayoutListener.java \
    $$PWD/qt/android/support/v7/widget/QmlRecyclerAdapter.java \
    $$PWD/qt/android/view/QmlMenu.java \
    $$PWD/qt/android/view/QmlMenuItem.java \
    $$PWD/qt/android/view/QmlViewListener.java \
    $$PWD/qt/android/widget/QmlCompoundButtonListener.java \
    $$PWD/qt/android/widget/QmlNumberPickerListener.java \
    $$PWD/qt/android/widget/QmlRadioGroupListener.java \
    $$PWD/qt/android/widget/QmlRatingBarListener.java \
    $$PWD/qt/android/widget/QmlScrollView.java \
    $$PWD/qt/android/widget/QmlSeekBarListener.java \
    $$PWD/qt/android/widget/QmlTabHostListener.java

java.files = $$PWD/qt
java.path = $$[QT_INSTALL_PREFIX]/src/java
INSTALLS += java

contains(QT_CONFIG, private_tests) {   # -developer-build
    QMAKE_POST_LINK += \
        $${QMAKE_COPY_DIR} $$shell_path($$PWD/qt) $$shell_path($$java.path)
}
