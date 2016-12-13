TEMPLATE = subdirs
SUBDIRS += \
    qmlandroid \
    imports \
    android

imports.depends = qmlandroid
