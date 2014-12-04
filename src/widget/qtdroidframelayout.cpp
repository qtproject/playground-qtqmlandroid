#include "qtdroidframelayout_p.h"

QtDroidFrameLayout::QtDroidFrameLayout(QtDroidView *parent) : QtDroidViewGroup(parent)
{
}

QtDroidFrameLayoutParams *QtDroidFrameLayout::qmlAttachedProperties(QObject *object)
{
    QtDroidView *view = qobject_cast<QtDroidView*>(object);
    if (view)
        return new QtDroidFrameLayoutParams(view);
    return 0;
}

QAndroidJniObject QtDroidFrameLayout::construct()
{
    return QAndroidJniObject("android/widget/FrameLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidFrameLayout::inflate()
{
    QtDroidViewGroup::inflate();
}
