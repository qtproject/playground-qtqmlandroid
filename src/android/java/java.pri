OTHER_FILES += \
    $$PWD/native/qt/android/app/QmlActivity.java \
    $$PWD/native/qt/android/app/QmlService.java \
    $$PWD/native/qt/android/support/v4/widget/QmlSwipeRefreshLayoutListener.java \
    $$PWD/native/qt/android/support/v7/widget/QmlRecyclerAdapter.java \
    $$PWD/native/qt/android/view/QmlMenu.java \
    $$PWD/native/qt/android/view/QmlMenuItem.java \
    $$PWD/native/qt/android/view/QmlViewListener.java \
    $$PWD/native/qt/android/widget/QmlCompoundButtonListener.java \
    $$PWD/native/qt/android/widget/QmlNumberPickerListener.java \
    $$PWD/native/qt/android/widget/QmlRadioGroupListener.java \
    $$PWD/native/qt/android/widget/QmlRatingBarListener.java \
    $$PWD/native/qt/android/widget/QmlScrollView.java \
    $$PWD/native/qt/android/widget/QmlSeekBarListener.java \
    $$PWD/natiev/qt/android/widget/QmlTabHostListener.java

java.files = $$PWD/native
java.path = $$[QT_INSTALL_PREFIX]/src/android/java
!prefix_build: COPIES += java
INSTALLS += java
