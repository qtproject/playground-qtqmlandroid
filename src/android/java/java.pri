OTHER_FILES += \
    $$PWD/src/org/qtproject/qt5/android/bindings/app/QtNativeActivity.java \
    $$PWD/src/org/qtproject/qt5/android/bindings/app/QtNativeService.java \
    $$PWD/src/org/qtproject/qt5/android/bindings/view/QtNativeMenu.java \
    $$PWD/src/org/qtproject/qt5/android/bindings/view/QtNativeMenuItem.java \
    $$PWD/src/org/qtproject/qt5/android/bindings/view/QtNativeViewListener.java \
    $$PWD/src/org/qtproject/qt5/android/bindings/widget/QtNativeCompoundButtonListener.java \
    $$PWD/src/org/qtproject/qt5/android/bindings/widget/QtNativeNumberPickerListener.java \
    $$PWD/src/org/qtproject/qt5/android/bindings/widget/QtNativeRadioGroupListener.java \
    $$PWD/src/org/qtproject/qt5/android/bindings/widget/QtNativeRatingBarListener.java \
    $$PWD/src/org/qtproject/qt5/android/bindings/widget/QtNativeScrollView.java \
    $$PWD/src/org/qtproject/qt5/android/bindings/widget/QtNativeSeekBarListener.java \
    $$PWD/src/org/qtproject/qt5/android/bindings/widget/QtNativeTabHostListener.java \
    $$PWD/support/v4/widget/QtNativeSwipeRefreshLayoutListener.java \
    $$PWD/support/v7/widget/QtNativeRecyclerAdapter.java

java.files = $$PWD/src $$PWD/support
java.path = $$[QT_INSTALL_PREFIX]/src/android/java
!prefix_build: COPIES += java
INSTALLS += java
