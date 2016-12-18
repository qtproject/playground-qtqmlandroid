TARGET = QtQmlAndroid
MODULE = qmlandroid

QT += androidextras qml
QT += core-private # qjnihelpers

CONFIG += c++11
CONFIG -= create_cmake

features.files = $$MODULE_PREFIX/features/qmlandroid.prf
features.path = $$[QT_HOST_DATA]/mkspecs/features
!prefix_build: COPIES += features
INSTALLS += features

include(android.pri)
include(java/java.pri)

load(qt_module)
