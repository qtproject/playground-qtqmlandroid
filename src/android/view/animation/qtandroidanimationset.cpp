#include "qtandroidanimationset_p.h"

QT_BEGIN_NAMESPACE

QtAndroidAnimationSet::QtAndroidAnimationSet(QObject *parent) :
    QtAndroidAnimation(parent), m_shareInterpolator(false)
{
}

bool QtAndroidAnimationSet::shareInterpolator() const
{
    return m_shareInterpolator;
}

void QtAndroidAnimationSet::setShareInterpolator(bool share)
{
    if (m_shareInterpolator != share) {
        m_shareInterpolator = share;
        emit shareInterpolatorChanged();
    }
}

QAndroidJniObject QtAndroidAnimationSet::onCreate()
{
    return QAndroidJniObject("android/view/animation/AnimationSet",
                             "(Z)V",
                             m_shareInterpolator);
}

void QtAndroidAnimationSet::onInflate(QAndroidJniObject &instance)
{
    QtAndroidAnimation::onInflate(instance);

    foreach (QObject *object, children()) {
        QtAndroidAnimation *child = qobject_cast<QtAndroidAnimation *>(object);
        if (child) {
            QAndroidJniObject animation = child->instance();
            if (animation.isValid())
                instance.callMethod<void>("addAnimation", "(Landroid/view/animation/Animation;)V", animation.object());
        }
    }
}

QT_END_NAMESPACE
