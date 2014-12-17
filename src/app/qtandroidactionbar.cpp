#include "qtandroidactionbar_p.h"
#include "qtandroidfunctions_p.h"
#include "qtandroiddrawable_p.h"

QT_BEGIN_NAMESPACE

QtAndroidActionBar::QtAndroidActionBar(QObject *parent) :
    QtAndroidObject(parent), m_visible(true), m_elevation(0.0), m_background(0)
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

QtAndroidDrawable *QtAndroidActionBar::background() const
{
    return m_background;
}

void QtAndroidActionBar::setBackground(QtAndroidDrawable *background)
{
    if (m_background != background) {
        if (m_background) {
            disconnect(m_background, &QtAndroidObject::instanceChanged, this, &QtAndroidActionBar::updateBackground);
            m_background->destruct();
        }
        m_background = background;
        if (m_background) {
            connect(m_background, &QtAndroidObject::instanceChanged, this, &QtAndroidActionBar::updateBackground);
            m_background->construct();
        }
        emit backgroundChanged();
    }
}

void QtAndroidActionBar::onInflate(QAndroidJniObject &instance)
{
    instance.callMethod<void>(m_visible ? "show" : "hide");

    if (!m_title.isNull())
        instance.callMethod<void>("setTitle", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_title).object());
    if (!m_subtitle.isNull())
        instance.callMethod<void>("setSubtitle", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_subtitle).object());

    // TODO: properties
    instance.callMethod<void>("setElevation", "(F)V", m_elevation);
    instance.callMethod<void>("setDisplayHomeAsUpEnabled", "(Z)V", true);
    instance.callMethod<void>("setHomeButtonEnabled", "(Z)V", true);
}

void QtAndroidActionBar::objectChange(ObjectChange change)
{
    QtAndroidObject::objectChange(change);
    if (change == InstanceChange)
        updateBackground();
}

void QtAndroidActionBar::updateBackground()
{
    if (!isValid() || !m_background)
        return;

    QAndroidJniObject bar = instance();
    QAndroidJniObject background = m_background->instance();
    QtAndroid::callFunction([=]() {
        bar.callMethod<void>("setBackgroundDrawable", "(Landroid/graphics/drawable/Drawable;)V", background.object());
    });
}

QT_END_NAMESPACE
