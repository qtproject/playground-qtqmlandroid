#include "qtdroidframelayout_p.h"

QtDroidFrameLayout::QtDroidFrameLayout(QObject *parent) : QtDroidViewGroup(parent)
{
}

QtDroidFrameLayoutParams *QtDroidFrameLayout::qmlAttachedProperties(QObject *object)
{
    QtDroidView *view = qobject_cast<QtDroidView*>(object);
    if (view)
        return new QtDroidFrameLayoutParams(view);
    return 0;
}

QAndroidJniObject QtDroidFrameLayout::construct(jobject context)
{
    return QAndroidJniObject("android/widget/FrameLayout",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidFrameLayout::inflate(jobject context)
{
    QtDroidViewGroup::inflate(context);
}
