#include "qtdroidviewswitcher_p.h"

QtDroidViewSwitcher::QtDroidViewSwitcher(QtDroidView *parent) : QtDroidViewAnimator(parent)
{
}

QAndroidJniObject QtDroidViewSwitcher::construct()
{
    return QAndroidJniObject("android/widget/ViewSwitcher",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidViewSwitcher::inflate()
{
    QtDroidViewAnimator::inflate();
}
