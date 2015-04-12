TEMPLATE = subdirs
SUBDIRS += \
    qmlandroid \
    imports \
    java

imports.depends = qmlandroid
