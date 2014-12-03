#include "qtdroidmenu_p.h"
#include "qtdroidmenuitem_p.h"

QtDroidMenu::QtDroidMenu(QObject *parent) : QtDroidObject(parent)
{
}

QList<QtDroidMenuItem *> QtDroidMenu::items() const
{
    QList<QtDroidMenuItem *> lst;
    foreach (QObject *child, children()) {
        QtDroidMenuItem *item = qobject_cast<QtDroidMenuItem *>(child);
        if (item)
            lst += item;
    }
    return lst;
}
