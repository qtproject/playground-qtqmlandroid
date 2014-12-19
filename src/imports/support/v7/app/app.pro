TARGET = qtqmlandroidsupportv7appplugin
TARGETPATH = android/support/v7/app
IMPORT_VERSION = 0.21

QT += qmlandroid-private

SOURCES += \
    $$PWD/qtqmlandroidsupportv7appplugin.cpp

CONFIG += no_cxx_module
load(qml_plugin)
