#include "qtdroidviewswitcher_p.h"

QtAndroidViewSwitcher::QtAndroidViewSwitcher(QtAndroidView *parent) : QtAndroidViewAnimator(parent)
{
}

QAndroidJniObject QtAndroidViewSwitcher::construct()
{
    return QAndroidJniObject("android/widget/ViewSwitcher",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidViewSwitcher::inflate()
{
    QtAndroidViewAnimator::inflate();
}
