#include "qtandroidviewflipper_p.h"

QtAndroidViewFlipper::QtAndroidViewFlipper(QtAndroidView *parent) : QtAndroidViewAnimator(parent)
{
}

QAndroidJniObject QtAndroidViewFlipper::construct()
{
    return QAndroidJniObject("android/widget/ViewFlipper",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidViewFlipper::inflate()
{
    QtAndroidViewAnimator::inflate();
}
