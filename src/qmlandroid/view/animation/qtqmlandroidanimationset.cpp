#include "qtqmlandroidanimationset_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidAnimationSet::QQmlAndroidAnimationSet(QObject *parent) :
    QQmlAndroidAnimation(parent), m_shareInterpolator(false)
{
}

bool QQmlAndroidAnimationSet::shareInterpolator() const
{
    return m_shareInterpolator;
}

void QQmlAndroidAnimationSet::setShareInterpolator(bool share)
{
    if (m_shareInterpolator != share) {
        m_shareInterpolator = share;
        emit shareInterpolatorChanged();
    }
}

QAndroidJniObject QQmlAndroidAnimationSet::onCreate()
{
    return QAndroidJniObject("android/view/animation/AnimationSet",
                             "(Z)V",
                             m_shareInterpolator);
}

void QQmlAndroidAnimationSet::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidAnimation::onInflate(instance);

    foreach (QObject *object, children()) {
        QQmlAndroidAnimation *child = qobject_cast<QQmlAndroidAnimation *>(object);
        if (child) {
            QAndroidJniObject animation = child->instance();
            if (animation.isValid())
                instance.callMethod<void>("addAnimation", "(Landroid/view/animation/Animation;)V", animation.object());
        }
    }
}

QT_END_NAMESPACE
