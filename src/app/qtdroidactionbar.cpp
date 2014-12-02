#include "qtdroidactionbar_p.h"

QtDroidActionBar::QtDroidActionBar(QObject *parent) : QtDroidObject(parent), m_visible(true), m_activity(0)
{
}

bool QtDroidActionBar::isVisible() const
{
    return m_visible;
}

static void callSetVisible(const QAndroidJniObject& bar, bool visible)
{
    if (bar.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            if (visible)
                bar.callMethod<void>("show");
            else
                bar.callMethod<void>("hide");
        });
    }
}

void QtDroidActionBar::setVisible(bool arg)
{
    if (arg != isVisible()) {
        m_visible = arg;
        callSetVisible(instance(), arg);
        emit visibleChanged();
    }
}

QString QtDroidActionBar::title() const
{
    return m_title;
}

static void callSetTitle(const QAndroidJniObject& bar, const char* method, const QString &title)
{
    if (bar.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            bar.callMethod<void>(method, "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(title).object());
        });
    }
}

void QtDroidActionBar::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        callSetTitle(instance(), "setTitle", title);
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
        callSetTitle(instance(), "setSubtitle", subtitle);
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
        callSetVisible(instance(), m_visible);
        if (!m_title.isNull())
            callSetTitle(instance(), "setTitle", m_title);
        if (!m_subtitle.isNull())
            callSetTitle(instance(), "setSubtitle", m_subtitle);
    }
}
