#include "qtandroidviewswitcher_p.h"

QT_BEGIN_NAMESPACE

QtAndroidViewSwitcher::QtAndroidViewSwitcher(QtAndroidView *parent) :
    QtAndroidViewAnimator(parent)
{
}

QAndroidJniObject QtAndroidViewSwitcher::onCreate()
{
    return QAndroidJniObject("android/widget/ViewSwitcher",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidViewSwitcher::onInflate(QAndroidJniObject &instance)
{
    QtAndroidViewAnimator::onInflate(instance);
}

QT_END_NAMESPACE
