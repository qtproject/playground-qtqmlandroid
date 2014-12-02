TEMPLATE = app
TARGET = qtdroid
QT += androidextras qml core-private # qjnihelpers
SOURCES += main.cpp
RESOURCES += qtdroid.qrc

include(src/src.pri)
