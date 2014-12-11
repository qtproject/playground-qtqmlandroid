#include "qtandroidframelayout_p.h"

QtAndroidFrameLayout::QtAndroidFrameLayout(QtAndroidView *parent) : QtAndroidViewGroup(parent)
{
}

QtAndroidFrameLayoutParams *QtAndroidFrameLayout::qmlAttachedProperties(QObject *object)
{
    QtAndroidView *view = qobject_cast<QtAndroidView*>(object);
    if (view)
        return new QtAndroidFrameLayoutParams(view);
    return 0;
}

QAndroidJniObject QtAndroidFrameLayout::construct()
{
    return QAndroidJniObject("android/widget/FrameLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidFrameLayout::inflate()
{
    QtAndroidViewGroup::inflate();
}
