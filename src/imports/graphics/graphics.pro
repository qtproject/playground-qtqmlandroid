TARGET = qtqmlandroidgraphicsplugin
TARGETPATH = android/graphics
IMPORT_VERSION = 0.21

QT += qmlandroid-private

SOURCES += \
    $$PWD/qtqmlandroidgraphicsplugin.cpp

CONFIG += no_cxx_module
load(qml_plugin)
