#include "qtqmlandroidanimationset_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidAnimationSet::QtQmlAndroidAnimationSet(QObject *parent) :
    QtQmlAndroidAnimation(parent), m_shareInterpolator(false)
{
}

bool QtQmlAndroidAnimationSet::shareInterpolator() const
{
    return m_shareInterpolator;
}

void QtQmlAndroidAnimationSet::setShareInterpolator(bool share)
{
    if (m_shareInterpolator != share) {
        m_shareInterpolator = share;
        emit shareInterpolatorChanged();
    }
}

QAndroidJniObject QtQmlAndroidAnimationSet::onCreate()
{
    return QAndroidJniObject("android/view/animation/AnimationSet",
                             "(Z)V",
                             m_shareInterpolator);
}

void QtQmlAndroidAnimationSet::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidAnimation::onInflate(instance);

    foreach (QObject *object, children()) {
        QtQmlAndroidAnimation *child = qobject_cast<QtQmlAndroidAnimation *>(object);
        if (child) {
            QAndroidJniObject animation = child->instance();
            if (animation.isValid())
                instance.callMethod<void>("addAnimation", "(Landroid/view/animation/Animation;)V", animation.object());
        }
    }
}

QT_END_NAMESPACE
