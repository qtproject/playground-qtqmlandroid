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

QAndroidJniObject QtDroidRelativeLayout::construct(jobject context)
{
    return QAndroidJniObject("android/widget/RelativeLayout",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidRelativeLayout::inflate(jobject context)
{
    QtDroidViewGroup::inflate(context);
}
