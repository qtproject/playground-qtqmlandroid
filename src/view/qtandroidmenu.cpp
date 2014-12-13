#include "qtandroidmenu_p.h"
#include "qtandroidmenuitem_p.h"

QtAndroidMenu::QtAndroidMenu(QObject *parent) : QtAndroidObject(parent)
{
}

QList<QtAndroidMenuItem *> QtAndroidMenu::items() const
{
    QList<QtAndroidMenuItem *> lst;
    foreach (QObject *child, children()) {
        QtAndroidMenuItem *item = qobject_cast<QtAndroidMenuItem *>(child);
        if (item)
            lst += item;
    }
    return lst;
}