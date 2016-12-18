TEMPLATE = app
TARGET = catalog
QT += qml nativeandroid

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
ANDROID_SUPPORT = v4 v7

target.path = $$[QT_INSTALL_EXAMPLES]/nativeandroid/catalog
INSTALLS += target
