OTHER_FILES += \
    $$PWD/native/qt/android/app/QtNativeActivity.java \
    $$PWD/native/qt/android/app/QtNativeService.java \
    $$PWD/native/qt/android/support/v4/widget/QtNativeSwipeRefreshLayoutListener.java \
    $$PWD/native/qt/android/support/v7/widget/QtNativeRecyclerAdapter.java \
    $$PWD/native/qt/android/view/QtNativeMenu.java \
    $$PWD/native/qt/android/view/QtNativeMenuItem.java \
    $$PWD/native/qt/android/view/QtNativeViewListener.java \
    $$PWD/native/qt/android/widget/QtNativeCompoundButtonListener.java \
    $$PWD/native/qt/android/widget/QtNativeNumberPickerListener.java \
    $$PWD/native/qt/android/widget/QtNativeRadioGroupListener.java \
    $$PWD/native/qt/android/widget/QtNativeRatingBarListener.java \
    $$PWD/native/qt/android/widget/QtNativeScrollView.java \
    $$PWD/native/qt/android/widget/QtNativeSeekBarListener.java \
    $$PWD/natiev/qt/android/widget/QtNativeTabHostListener.java

java.files = $$PWD/native
java.path = $$[QT_INSTALL_PREFIX]/src/android/java
!prefix_build: COPIES += java
INSTALLS += java
