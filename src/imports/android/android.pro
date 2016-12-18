TARGET = qtqmlandroidplugin
TARGETPATH = android
IMPORT_VERSION = 0.21

QT += nativeandroid-private

SOURCES += \
    $$PWD/qtqmlandroidplugin.cpp

CONFIG += no_cxx_module
load(qml_plugin)
