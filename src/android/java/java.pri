OTHER_FILES += \
    $$PWD/qml/qt/android/app/QmlActivity.java \
    $$PWD/qml/qt/android/app/QmlService.java \
    $$PWD/qml/qt/android/support/v4/widget/QmlSwipeRefreshLayoutListener.java \
    $$PWD/qml/qt/android/support/v7/widget/QmlRecyclerAdapter.java \
    $$PWD/qml/qt/android/view/QmlMenu.java \
    $$PWD/qml/qt/android/view/QmlMenuItem.java \
    $$PWD/qml/qt/android/view/QmlViewListener.java \
    $$PWD/qml/qt/android/widget/QmlCompoundButtonListener.java \
    $$PWD/qml/qt/android/widget/QmlNumberPickerListener.java \
    $$PWD/qml/qt/android/widget/QmlRadioGroupListener.java \
    $$PWD/qml/qt/android/widget/QmlRatingBarListener.java \
    $$PWD/qml/qt/android/widget/QmlScrollView.java \
    $$PWD/qml/qt/android/widget/QmlSeekBarListener.java \
    $$PWD/qml/qt/android/widget/QmlTabHostListener.java

java.files = $$PWD/qml
java.path = $$[QT_INSTALL_PREFIX]/src/android/java
!prefix_build: COPIES += java
INSTALLS += java
