TARGET  = QtQmlAndroid

QT += androidextras qml
QT += core-private # qjnihelpers

CONFIG += c++11
CONFIG -= create_cmake

include(qmlandroid.pri)

load(qt_module)
