TEMPLATE = app
TARGET = qtandroid
QT += androidextras qml core-private # qjnihelpers
SOURCES += main.cpp
RESOURCES += qtandroid.qrc

include(src/src.pri)
