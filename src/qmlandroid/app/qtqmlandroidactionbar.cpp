#include "qtqmlandroidactionbar_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qtqmlandroiddrawable_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidActionBar::QtQmlAndroidActionBar(QObject *parent) :
    QtQmlAndroidObject(parent), m_visible(true), m_elevation(0.0), m_background(0)
{
}

bool QtQmlAndroidActionBar::isVisible() const
{
    return m_visible;
}

void QtQmlAndroidActionBar::setVisible(bool arg)
{
    if (arg != isVisible()) {
        m_visible = arg;
        if (arg)
            QtQmlAndroid::callVoidMethod(instance(), "show");
        else
            QtQmlAndroid::callVoidMethod(instance(), "hide");
        emit visibleChanged();
    }
}

qreal QtQmlAndroidActionBar::elevation() const
{
    return m_elevation;
}

void QtQmlAndroidActionBar::setElevation(qreal elevation)
{
    if (m_elevation != elevation) {
        m_elevation = elevation;
        QtQmlAndroid::callRealMethod(instance(), "setElevation", elevation);
        emit elevationChanged();
    }
}

QString QtQmlAndroidActionBar::title() const
{
    return m_title;
}

void QtQmlAndroidActionBar::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        QtQmlAndroid::callTextMethod(instance(), "setTitle", title);
        emit titleChanged();
    }
}

QString QtQmlAndroidActionBar::subtitle() const
{
    return m_subtitle;
}

void QtQmlAndroidActionBar::setSubtitle(const QString &subtitle)
{
    if (m_subtitle != subtitle) {
        m_subtitle = subtitle;
        QtQmlAndroid::callTextMethod(instance(), "setSubtitle", subtitle);
        emit subtitleChanged();
    }
}

QtQmlAndroidDrawable *QtQmlAndroidActionBar::background() const
{
    return m_background;
}

void QtQmlAndroidActionBar::setBackground(QtQmlAndroidDrawable *background)
{
    if (m_background != background) {
        if (m_background) {
            disconnect(m_background, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidActionBar::updateBackground);
            m_background->destruct();
        }
        m_background = background;
        if (m_background) {
            connect(m_background, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidActionBar::updateBackground);
            m_background->construct();
        }
        emit backgroundChanged();
    }
}

void QtQmlAndroidActionBar::onInflate(QAndroidJniObject &instance)
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

void QtQmlAndroidActionBar::objectChange(ObjectChange change)
{
    QtQmlAndroidObject::objectChange(change);
    if (change == InstanceChange)
        updateBackground();
}

void QtQmlAndroidActionBar::updateBackground()
{
    if (!isValid() || !m_background)
        return;

    QAndroidJniObject bar = instance();
    QAndroidJniObject background = m_background->instance();
    QtQmlAndroid::callFunction([=]() {
        bar.callMethod<void>("setBackgroundDrawable", "(Landroid/graphics/drawable/Drawable;)V", background.object());
    });
}

QT_END_NAMESPACE
