#include "qtqmlandroidspace_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidSpace::QtQmlAndroidSpace(QtQmlAndroidView *parent) :
    QtQmlAndroidView(parent)
{
}

QAndroidJniObject QtQmlAndroidSpace::onCreate()
{
    return QAndroidJniObject("android/widget/Space",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidSpace::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidView::onInflate(instance);
}

QT_END_NAMESPACE
