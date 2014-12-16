#include "qtandroidanimation_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidAnimation::QtAndroidAnimation(QObject *parent) :
    QtAndroidContextual(parent), m_resource(0)
{
}

int QtAndroidAnimation::resource() const
{
    return m_resource;
}

void QtAndroidAnimation::setResource(int resource)
{
    if (m_resource != resource) {
        m_resource = resource;
        emit resourceChanged();
    }
}

int QtAndroidAnimation::repeatCount() const
{
    if (m_repeatCount.isNull())
        return -1;
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

void QtAndroidAnimation::cancel()
{
    QtAndroid::callVoidMethod(instance(), "cancel");
}

void QtAndroidAnimation::start()
{
    QtAndroid::callVoidMethod(instance(), "start");
}

QAndroidJniObject QtAndroidAnimation::onCreate()
{
    return QAndroidJniObject::callStaticObjectMethod("android/view/animation/AnimationUtils",
                                                     "loadAnimation",
                                                     "(Landroid/content/Context;I)Landroid/view/animation/Animation;",
                                                     ctx().object(),
                                                     m_resource);
}

void QtAndroidAnimation::onInflate(QAndroidJniObject &instance)
{
    QtAndroidContextual::onInflate(instance);

    if (!m_repeatCount.isNull())
        instance.callMethod<void>("setRepeatCount", "(I)V", m_repeatCount.value());
}
