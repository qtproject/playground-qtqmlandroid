#include "qqmlandroidspace_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidSpace::QQmlAndroidSpace(QQmlAndroidView *parent) :
    QQmlAndroidView(parent)
{
}

QAndroidJniObject QQmlAndroidSpace::onCreate()
{
    return QAndroidJniObject("android/widget/Space",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidSpace::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidView::onInflate(instance);
}

QT_END_NAMESPACE
