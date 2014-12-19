#include "qtqmlandroidviewflipper_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidViewFlipper::QQmlAndroidViewFlipper(QQmlAndroidView *parent) :
    QQmlAndroidViewAnimator(parent)
{
}

QAndroidJniObject QQmlAndroidViewFlipper::onCreate()
{
    return QAndroidJniObject("android/widget/ViewFlipper",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidViewFlipper::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidViewAnimator::onInflate(instance);
}

QT_END_NAMESPACE
