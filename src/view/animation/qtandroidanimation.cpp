#include "qtandroidanimation_p.h"
#include "qtandroidfunctions_p.h"
#include "qtandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidAnimation::QtAndroidAnimation(QObject *parent) :
    QtAndroidContextual(parent), m_interpolator(0)
{
}

int QtAndroidAnimation::resource() const
{
    if (m_resource.isNull())
        return 0;
    return m_resource.value();
}

void QtAndroidAnimation::setResource(int resource)
{
    if (m_resource.isNull() || m_resource.value() != resource) {
        m_resource = resource;
        emit resourceChanged();
    }
}

int QtAndroidAnimation::duration() const
{
    if (m_duration.isNull())
        return 0;
    return m_duration.value();
}

void QtAndroidAnimation::setDuration(int duration)
{
    if (m_duration.isNull() || m_duration.value() != duration) {
        m_duration = duration;
        QtAndroid::callIntMethod(instance(), "setDuration", duration);
        emit durationChanged();
    }
}

bool QtAndroidAnimation::fillAfter() const
{
    if (m_fillAfter.isNull())
        return false;
    return m_fillAfter.value();
}

void QtAndroidAnimation::setFillAfter(bool fill)
{
    if (m_fillAfter.isNull() || m_fillAfter.value() != fill) {
        m_fillAfter = fill;
        QtAndroid::callBoolMethod(instance(), "setFillAfter", fill);
        emit fillAfterChanged();
    }
}

bool QtAndroidAnimation::fillBefore() const
{
    if (m_fillBefore.isNull())
        return true;
    return m_fillBefore.value();
}

void QtAndroidAnimation::setFillBefore(bool fill)
{
    if (m_fillBefore.isNull() || m_fillBefore.value() != fill) {
        m_fillBefore = fill;
        QtAndroid::callBoolMethod(instance(), "setFillBefore", fill);
        emit fillBeforeChanged();
    }
}

bool QtAndroidAnimation::fillEnabled() const
{
    if (!m_fillEnabled.isNull())
        return false;
    return m_fillEnabled.value();
}

void QtAndroidAnimation::setFillEnabled(bool fill)
{
    if (m_fillEnabled.isNull() || m_fillEnabled.value()!= fill) {
        m_fillEnabled = fill;
        QtAndroid::callBoolMethod(instance(), "setFillEnabled", fill);
        emit fillEnabledChanged();
    }
}

QtAndroidInterpolator *QtAndroidAnimation::interpolator() const
{
    return m_interpolator;
}

void QtAndroidAnimation::setInterpolator(QtAndroidInterpolator *interpolator)
{
    if (m_interpolator != interpolator) {
        if (m_interpolator) {
            disconnect(m_interpolator, &QtAndroidObject::instanceChanged, this, &QtAndroidAnimation::updateInterpolator);
            m_interpolator->destruct();
        }
        m_interpolator = interpolator;
        if (m_interpolator) {
            connect(m_interpolator, &QtAndroidObject::instanceChanged, this, &QtAndroidAnimation::updateInterpolator);
            if (isValid())
                m_interpolator->construct();
        }
    }
}

int QtAndroidAnimation::repeatCount() const
{
    if (m_repeatCount.isNull())
        return 0;
    return m_repeatCount.value();
}

void QtAndroidAnimation::setRepeatCount(int count)
{
    if (m_repeatCount.isNull() || m_repeatCount.value() != count) {
        m_repeatCount = count;
        QtAndroid::callIntMethod(instance(), "setRepeatCount", count);
        emit repeatCountChanged();
    }
}

QtAndroidAnimation::RepeatMode QtAndroidAnimation::repeatMode() const
{
    if (m_repeatMode.isNull())
        return RESTART;
    return m_repeatMode.value();
}

void QtAndroidAnimation::setRepeatMode(RepeatMode mode)
{
    if (m_repeatMode.isNull() || m_repeatMode.value() != mode) {
        m_repeatMode = mode;
        QtAndroid::callIntMethod(instance(), "setRepeatMode", mode);
        emit repeatModeChanged();
    }
}

int QtAndroidAnimation::startOffset() const
{
    if (m_startOffset.isNull())
        return 0;
    return m_startOffset.value();
}

void QtAndroidAnimation::setStartOffset(int offset)
{
    if (m_startOffset.isNull() || m_startOffset.value() != offset) {
        m_startOffset = offset;
        QtAndroid::callIntMethod(instance(), "setStartOffset", offset);
        emit startOffsetChanged();
    }
}

QtAndroidAnimation::ZAdjustment QtAndroidAnimation::zAdjustment() const
{
    if (m_zAdjustment.isNull())
        return ZORDER_NORMAL;
    return m_zAdjustment.value();
}

void QtAndroidAnimation::setZAdjustment(ZAdjustment adjustment)
{
    if (m_zAdjustment.isNull() || m_zAdjustment.value() != adjustment) {
        m_zAdjustment = adjustment;
        QtAndroid::callIntMethod(instance(), "setZAdjustment", adjustment);
        emit zAdjustmentChanged();
    }
}

void QtAndroidAnimation::cancel()
{
    QtAndroid::callVoidMethod(instance(), "cancel");
}

void QtAndroidAnimation::start()
{
    QtAndroid::callVoidMethod(instance(), "start");
}

void QtAndroidAnimation::startNow()
{
    QtAndroid::callVoidMethod(instance(), "startNow");
}

QAndroidJniObject QtAndroidAnimation::onCreate()
{
    if (m_resource.isNull())
        return QAndroidJniObject("android/view/animation/Animation");

    return QAndroidJniObject::callStaticObjectMethod("android/view/animation/AnimationUtils",
                                                     "loadAnimation",
                                                     "(Landroid/content/Context;I)Landroid/view/animation/Animation;",
                                                     ctx().object(),
                                                     m_resource.value());
}

void QtAndroidAnimation::onInflate(QAndroidJniObject &instance)
{
    QtAndroidContextual::onInflate(instance);

    if (m_resource.isNull()) {
        if (!m_duration.isNull())
            instance.callMethod<void>("setDuration", "(J)V", static_cast<jlong>(m_duration.value()));
        if (!m_fillAfter.isNull())
            instance.callMethod<void>("setFillAfter", "(Z)V", m_fillAfter.value());
        if (!m_fillBefore.isNull())
            instance.callMethod<void>("setFillBefore", "(Z)V", m_fillBefore.value());
        if (!m_fillEnabled.isNull())
            instance.callMethod<void>("setFillEnabled", "(Z)V", m_fillEnabled.value());
        if (!m_repeatCount.isNull())
            instance.callMethod<void>("setRepeatCount", "(I)V", m_repeatCount.value());
        if (!m_repeatMode.isNull())
            instance.callMethod<void>("setRepeatMode", "(I)V", m_repeatMode.value());
        if (!m_startOffset.isNull())
            instance.callMethod<void>("setStartOffset", "(J)V", static_cast<jlong>(m_startOffset.value()));
        if (!m_zAdjustment.isNull())
            instance.callMethod<void>("setZAdjustment", "(I)V", m_zAdjustment.value());
    }
}

void QtAndroidAnimation::objectChange(ObjectChange change)
{
    if (change == InstanceChange)
        updateInterpolator();
}

void QtAndroidAnimation::updateInterpolator()
{
    if (!isValid() || !m_interpolator || !m_interpolator->isValid())
        return;

    QAndroidJniObject animation = instance();
    QAndroidJniObject interpolator = m_interpolator->instance();
    QtAndroid::callFunction([=]() {
        animation.callMethod<void>("setInterpolator", "(Landroid/view/animation/Interpolator;)V", interpolator.object());
    });
}

QT_END_NAMESPACE
