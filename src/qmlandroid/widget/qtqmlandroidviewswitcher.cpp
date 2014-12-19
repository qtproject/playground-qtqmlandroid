#include "qtqmlandroidviewswitcher_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidViewSwitcher::QtQmlAndroidViewSwitcher(QtQmlAndroidView *parent) :
    QtQmlAndroidViewAnimator(parent)
{
}

QAndroidJniObject QtQmlAndroidViewSwitcher::onCreate()
{
    return QAndroidJniObject("android/widget/ViewSwitcher",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidViewSwitcher::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidViewAnimator::onInflate(instance);
}

QT_END_NAMESPACE
