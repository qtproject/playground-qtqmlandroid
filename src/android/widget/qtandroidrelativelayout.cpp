#include "qtandroidrelativelayout_p.h"

QT_BEGIN_NAMESPACE

QtAndroidRelativeLayout::QtAndroidRelativeLayout(QtAndroidView *parent) :
    QtAndroidViewGroup(parent)
{
}

QtAndroidRelativeLayoutParams *QtAndroidRelativeLayout::qmlAttachedProperties(QObject *object)
{
    QtAndroidView *view = qobject_cast<QtAndroidView*>(object);
    if (view)
        return new QtAndroidRelativeLayoutParams(view);
    return 0;
}

QAndroidJniObject QtAndroidRelativeLayout::onCreate()
{
    return QAndroidJniObject("android/widget/RelativeLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidRelativeLayout::onInflate(QAndroidJniObject &instance)
{
    QtAndroidViewGroup::onInflate(instance);
}

QT_END_NAMESPACE
