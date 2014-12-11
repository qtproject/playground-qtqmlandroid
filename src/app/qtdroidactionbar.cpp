#include "qtdroidactionbar_p.h"
#include "qtdroidfunctions_p.h"

QtDroidActionBar::QtDroidActionBar(QObject *parent) :
    QtDroidObject(parent), m_visible(true), m_elevation(0.0), m_activity(0)
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
            QtDroid::callVoidMethod(instance(), "show");
        else
            QtDroid::callVoidMethod(instance(), "hide");
        emit visibleChanged();
    }
}

qreal QtDroidActionBar::elevation() const
{
    return m_elevation;
}

void QtDroidActionBar::setElevation(qreal elevation)
{
    if (m_elevation != elevation) {
        m_elevation = elevation;
        QtDroid::callRealMethod(instance(), "setElevation", elevation);
        emit elevationChanged();
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
        QtDroid::callTextMethod(instance(), "setTitle", title);
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
        QtDroid::callTextMethod(instance(), "setSubtitle", subtitle);
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
            QtDroid::callVoidMethod(instance(), "show");
        else
            QtDroid::callVoidMethod(instance(), "hide");
        QtDroid::callRealMethod(instance(), "setElevation", m_elevation);
        if (!m_title.isNull())
            QtDroid::callTextMethod(instance(), "setTitle", m_title);
        if (!m_subtitle.isNull())
            QtDroid::callTextMethod(instance(), "setSubtitle", m_subtitle);
    }
}
