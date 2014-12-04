#include "qtdroidrelativelayout_p.h"

QtDroidRelativeLayout::QtDroidRelativeLayout(QtDroidView *parent) : QtDroidViewGroup(parent)
{
}

QtDroidRelativeLayoutParams *QtDroidRelativeLayout::qmlAttachedProperties(QObject *object)
{
    QtDroidView *view = qobject_cast<QtDroidView*>(object);
    if (view)
        return new QtDroidRelativeLayoutParams(view);
    return 0;
}

QAndroidJniObject QtDroidRelativeLayout::construct()
{
    return QAndroidJniObject("android/widget/RelativeLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidRelativeLayout::inflate()
{
    QtDroidViewGroup::inflate();
}
