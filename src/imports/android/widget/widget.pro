TARGET = qtqmlandroidwidgetplugin
TARGETPATH = android/widget
IMPORT_VERSION = 0.21

QT += nativeandroid-private

SOURCES += \
    $$PWD/qtqmlandroidwidgetplugin.cpp

CONFIG += no_cxx_module
load(qml_plugin)
