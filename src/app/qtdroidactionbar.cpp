#include "qtdroidactionbar_p.h"

QtDroidActionBar::QtDroidActionBar(QObject *parent) : QtDroidObject(parent), m_visible(true), m_activity(0)
{
}

bool QtDroidActionBar::isVisible() const
{
    return m_visible;
}

void QtDroidActionBar::setVisible(bool arg)
{
    if (arg != isVisible()) {
        m_visible = arg;
        if (arg)
            callVoidMethod("show");
        else
            callVoidMethod("hide");
        emit visibleChanged();
    }
}

QString QtDroidActionBar::title() const
{
    return m_title;
}

void QtDroidActionBar::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        callTextMethod("setTitle", title);
        emit titleChanged();
    }
}

QString QtDroidActionBar::subtitle() const
{
    return m_subtitle;
}

void QtDroidActionBar::setSubtitle(const QString &subtitle)
{
    if (m_subtitle != subtitle) {
        m_subtitle = subtitle;
        callTextMethod("setSubtitle", subtitle);
        emit subtitleChanged();
    }
}

QtDroidActivity *QtDroidActionBar::activity() const
{
    return m_activity;
}

void QtDroidActionBar::setActivity(QtDroidActivity *activity)
{
    if (m_activity != activity) {
        m_activity = activity;
        if (m_visible)
            callVoidMethod("show");
        else
            callVoidMethod("hide");
        if (!m_title.isNull())
            callTextMethod("setTitle", m_title);
        if (!m_subtitle.isNull())
            callTextMethod("setSubtitle", m_subtitle);
    }
}
