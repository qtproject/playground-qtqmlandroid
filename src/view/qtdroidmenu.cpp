#include "qtdroidmenu_p.h"
#include "qtdroidmenuitem_p.h"

QtDroidMenu::QtDroidMenu(QObject *parent) : QtDroidObject(parent)
{
}

QList<QtDroidMenuItem *> QtDroidMenu::items() const
{
    return m_items;
}

void QtDroidMenu::objectAdded(QObject *object)
{
    QtDroidMenuItem *item = qobject_cast<QtDroidMenuItem *>(object);
    if (item)
        m_items += item;
}

void QtDroidMenu::objectRemoved(QObject *object)
{
    QtDroidMenuItem *item = qobject_cast<QtDroidMenuItem *>(object);
    if (item)
        m_items.removeOne(item);
}
