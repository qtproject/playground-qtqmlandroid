#include "qtdroidviewswitcher_p.h"

QtDroidViewSwitcher::QtDroidViewSwitcher(QtDroidView *parent) : QtDroidViewAnimator(parent)
{
}

QAndroidJniObject QtDroidViewSwitcher::construct(jobject context)
{
    return QAndroidJniObject("android/widget/ViewSwitcher",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidViewSwitcher::inflate(jobject context)
{
    QtDroidViewAnimator::inflate(context);
}
