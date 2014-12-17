#include "qtandroidspace_p.h"

QT_BEGIN_NAMESPACE

QtAndroidSpace::QtAndroidSpace(QtAndroidView *parent) :
    QtAndroidView(parent)
{
}

QAndroidJniObject QtAndroidSpace::onCreate()
{
    return QAndroidJniObject("android/widget/Space",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidSpace::onInflate(QAndroidJniObject &instance)
{
    QtAndroidView::onInflate(instance);
}

QT_END_NAMESPACE
