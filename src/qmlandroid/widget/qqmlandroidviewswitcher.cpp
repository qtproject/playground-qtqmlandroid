#include "qqmlandroidviewswitcher_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidViewSwitcher::QQmlAndroidViewSwitcher(QQmlAndroidView *parent) :
    QQmlAndroidViewAnimator(parent)
{
}

QAndroidJniObject QQmlAndroidViewSwitcher::onCreate()
{
    return QAndroidJniObject("android/widget/ViewSwitcher",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidViewSwitcher::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidViewAnimator::onInflate(instance);
}

QT_END_NAMESPACE
