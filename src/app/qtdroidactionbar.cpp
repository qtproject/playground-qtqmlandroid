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
    if (m_title.isNull())
        return QString();
    return m_title.value();
}

static void callSetTitle(const QAndroidJniObject& bar, const QString &title)
{
    if (bar.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            bar.callMethod<void>("setTitle", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(title).object());
        });
    }
}

void QtDroidActionBar::setTitle(const QString &arg)
{
    if (arg != title()) {
        m_title = arg;
        callSetTitle(instance(), arg);
        emit titleChanged();
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
            callSetTitle(instance(), m_title.value());
    }
}
