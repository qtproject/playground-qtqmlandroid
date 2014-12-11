#include "qtdroidactionbar_p.h"
#include "qtdroidfunctions_p.h"

QtAndroidActionBar::QtAndroidActionBar(QObject *parent) :
    QtAndroidObject(parent), m_visible(true), m_elevation(0.0), m_activity(0)
{
}

bool QtAndroidActionBar::isVisible() const
{
    return m_visible;
}

void QtAndroidActionBar::setVisible(bool arg)
{
    if (arg != isVisible()) {
        m_visible = arg;
        if (arg)
            QtAndroid::callVoidMethod(instance(), "show");
        else
            QtAndroid::callVoidMethod(instance(), "hide");
        emit visibleChanged();
    }
}

qreal QtAndroidActionBar::elevation() const
{
    return m_elevation;
}

void QtAndroidActionBar::setElevation(qreal elevation)
{
    if (m_elevation != elevation) {
        m_elevation = elevation;
        QtAndroid::callRealMethod(instance(), "setElevation", elevation);
        emit elevationChanged();
    }
}

QString QtAndroidActionBar::title() const
{
    return m_title;
}

void QtAndroidActionBar::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        QtAndroid::callTextMethod(instance(), "setTitle", title);
        emit titleChanged();
    }
}

QString QtAndroidActionBar::subtitle() const
{
    return m_subtitle;
}

void QtAndroidActionBar::setSubtitle(const QString &subtitle)
{
    if (m_subtitle != subtitle) {
        m_subtitle = subtitle;
        QtAndroid::callTextMethod(instance(), "setSubtitle", subtitle);
        emit subtitleChanged();
    }
}

QtAndroidActivity *QtAndroidActionBar::activity() const
{
    return m_activity;
}

void QtAndroidActionBar::setActivity(QtAndroidActivity *activity)
{
    if (m_activity != activity) {
        m_activity = activity;
        if (m_visible)
            QtAndroid::callVoidMethod(instance(), "show");
        else
            QtAndroid::callVoidMethod(instance(), "hide");
        QtAndroid::callRealMethod(instance(), "setElevation", m_elevation);
        if (!m_title.isNull())
            QtAndroid::callTextMethod(instance(), "setTitle", m_title);
        if (!m_subtitle.isNull())
            QtAndroid::callTextMethod(instance(), "setSubtitle", m_subtitle);
    }
}
