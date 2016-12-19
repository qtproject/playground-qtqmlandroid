TARGET = qtqmlandroidsupportv4widgetplugin
TARGETPATH = android/support/v4/widget
IMPORT_VERSION = 0.21

QT += nativeandroid-private

SOURCES += \
    $$PWD/qtqmlandroidsupportv4widgetplugin.cpp

CONFIG += no_cxx_module
load(qml_plugin)
