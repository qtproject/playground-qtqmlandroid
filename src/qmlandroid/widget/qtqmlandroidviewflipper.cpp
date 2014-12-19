#include "qtqmlandroidviewflipper_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidViewFlipper::QtQmlAndroidViewFlipper(QtQmlAndroidView *parent) :
    QtQmlAndroidViewAnimator(parent)
{
}

QAndroidJniObject QtQmlAndroidViewFlipper::onCreate()
{
    return QAndroidJniObject("android/widget/ViewFlipper",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidViewFlipper::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidViewAnimator::onInflate(instance);
}

QT_END_NAMESPACE
