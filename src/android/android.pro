TARGET  = qtandroidplugin
TARGETPATH = android
IMPORT_VERSION = 0.21

CONFIG += c++11
QT += androidextras qml
QT += core-private # qjnihelpers

include(android.pri)

CONFIG += no_cxx_module
load(qml_plugin)
