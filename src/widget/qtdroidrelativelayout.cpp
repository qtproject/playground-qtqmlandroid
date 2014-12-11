#include "qtdroidrelativelayout_p.h"

QtAndroidRelativeLayout::QtAndroidRelativeLayout(QtAndroidView *parent) : QtAndroidViewGroup(parent)
{
}

QtAndroidRelativeLayoutParams *QtAndroidRelativeLayout::qmlAttachedProperties(QObject *object)
{
    QtAndroidView *view = qobject_cast<QtAndroidView*>(object);
    if (view)
        return new QtAndroidRelativeLayoutParams(view);
    return 0;
}

QAndroidJniObject QtAndroidRelativeLayout::construct()
{
    return QAndroidJniObject("android/widget/RelativeLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidRelativeLayout::inflate()
{
    QtAndroidViewGroup::inflate();
}
