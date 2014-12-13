TEMPLATE = app
TARGET = qtandroid
QT += androidextras qml core-private # qjnihelpers
SOURCES += main.cpp
RESOURCES += qtandroid.qrc

include(src/src.pri)

DISTFILES += \
    src/java/gradle/wrapper/gradle-wrapper.jar \
    src/java/res/values/libs.xml \
    src/java/build.gradle \
    src/java/gradle/wrapper/gradle-wrapper.properties \
    src/java/gradlew \
    src/java/gradlew.bat
