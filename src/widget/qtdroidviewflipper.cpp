#include "qtdroidviewflipper_p.h"

QtDroidViewFlipper::QtDroidViewFlipper(QtDroidView *parent) : QtDroidViewAnimator(parent)
{
}

QAndroidJniObject QtDroidViewFlipper::construct(jobject context)
{
    return QAndroidJniObject("android/widget/ViewFlipper",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidViewFlipper::inflate(jobject context)
{
    QtDroidViewAnimator::inflate(context);
}
