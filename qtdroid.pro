TEMPLATE = app
TARGET = qtdroid
QT += androidextras qml quick
QT += core-private qml-private
SOURCES += main.cpp
RESOURCES += qtdroid.qrc

include(src/src.pri)
