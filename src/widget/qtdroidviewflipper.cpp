#include "qtdroidviewflipper_p.h"

QtDroidViewFlipper::QtDroidViewFlipper(QtDroidView *parent) : QtDroidViewAnimator(parent)
{
}

QAndroidJniObject QtDroidViewFlipper::construct()
{
    return QAndroidJniObject("android/widget/ViewFlipper",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidViewFlipper::inflate()
{
    QtDroidViewAnimator::inflate();
}
