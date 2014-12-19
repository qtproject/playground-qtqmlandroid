TARGET = qtqmlandroidviewplugin
TARGETPATH = android/view
IMPORT_VERSION = 0.21

QT += qmlandroid-private

SOURCES += \
    $$PWD/qtqmlandroidviewplugin.cpp

CONFIG += no_cxx_module
load(qml_plugin)
