#include "qtandroidspace_p.h"

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
