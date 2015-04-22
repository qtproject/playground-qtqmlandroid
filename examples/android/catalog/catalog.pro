TEMPLATE = app
TARGET = catalog
QT += qml qmlandroid

SOURCES += \
    main.cpp

RESOURCES += \
    catalog.qrc

OTHER_FILES += \
    qml/main.qml \
    qml/AwesomeView.qml \
    qml/ButtonView.qml \
    qml/InputView.qml \
    qml/ModelView.qml \
    qml/PickerView.qml \
    qml/ProgressView.qml

DISTFILES += \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
QMLANDROID_PACKAGES = app support view widget
