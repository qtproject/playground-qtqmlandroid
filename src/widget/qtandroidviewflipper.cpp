#include "qtandroidviewflipper_p.h"

QtAndroidViewFlipper::QtAndroidViewFlipper(QtAndroidView *parent) : QtAndroidViewAnimator(parent)
{
}

QAndroidJniObject QtAndroidViewFlipper::onCreate()
{
    return QAndroidJniObject("android/widget/ViewFlipper",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidViewFlipper::onInflate(QAndroidJniObject &instance)
{
    QtAndroidViewAnimator::onInflate(instance);
}
