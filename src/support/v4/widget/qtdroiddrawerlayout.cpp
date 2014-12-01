#include "qtdroiddrawerlayout_p.h"

QtDroidDrawerLayout::QtDroidDrawerLayout(QObject *parent) : QtDroidViewGroup(parent)
{
}

QtDroidDrawerLayoutParams *QtDroidDrawerLayout::qmlAttachedProperties(QObject *object)
{
    QtDroidView *view = qobject_cast<QtDroidView*>(object);
    if (view)
        return new QtDroidDrawerLayoutParams(view);
    return 0;
}

QAndroidJniObject QtDroidDrawerLayout::construct(jobject context)
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidDrawerLayout::inflate(jobject context)
{
    QtDroidViewGroup::inflate(context);
}
