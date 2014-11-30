#include "qtdroidframelayout_p.h"

QtDroidFrameLayout::QtDroidFrameLayout(QObject *parent) : QtDroidViewGroup(parent)
{
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
