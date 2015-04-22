requires(qtHaveModule(qml))
requires(qtHaveModule(androidextras))
load(qt_parts)

features.files = $$PWD/features/qmlandroid.prf
features.path = $$[QT_HOST_DATA]/mkspecs/features
INSTALLS += features
