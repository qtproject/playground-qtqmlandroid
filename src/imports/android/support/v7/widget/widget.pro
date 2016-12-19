TARGET = qtqmlandroidsupportv7widgetplugin
TARGETPATH = android/support/v7/widget
IMPORT_VERSION = 0.21

QT += nativeandroid-private

SOURCES += \
    $$PWD/qtqmlandroidsupportv7widgetplugin.cpp

CONFIG += no_cxx_module
load(qml_plugin)
