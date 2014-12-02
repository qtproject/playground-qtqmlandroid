#include "qtdroidmenuitem_p.h"

QtDroidMenuItem::QtDroidMenuItem(QObject *parent) : QObject(parent)
{
}

QString QtDroidMenuItem::title() const
{
    return m_title;
}

void QtDroidMenuItem::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        emit titleChanged();
    }
}
