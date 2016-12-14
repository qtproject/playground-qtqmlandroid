TEMPLATE = subdirs
SUBDIRS += \
    android \
    imports

imports.depends = android
