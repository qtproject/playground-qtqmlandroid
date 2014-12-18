#include "qtandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

QtAndroidFrameLayout::QtAndroidFrameLayout(QtAndroidView *parent) :
    QtAndroidViewGroup(parent)
{
}

QtAndroidFrameLayoutParams *QtAndroidFrameLayout::qmlAttachedProperties(QObject *object)
{
    QtAndroidView *view = qobject_cast<QtAndroidView*>(object);
    if (view)
        return new QtAndroidFrameLayoutParams(view);
    return 0;
}

QAndroidJniObject QtAndroidFrameLayout::onCreate()
{
    return QAndroidJniObject("android/widget/FrameLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidFrameLayout::onInflate(QAndroidJniObject &instance)
{
    QtAndroidViewGroup::onInflate(instance);
}

QT_END_NAMESPACE
