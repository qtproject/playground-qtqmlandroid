#include "qtdroidmenuitem_p.h"

QtAndroidMenuItem::QtAndroidMenuItem(QObject *parent) : QObject(parent)
{
}

QString QtAndroidMenuItem::title() const
{
    return m_title;
}

void QtAndroidMenuItem::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        emit titleChanged();
    }
}
