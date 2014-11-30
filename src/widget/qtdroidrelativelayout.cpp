#include "qtdroidrelativelayout_p.h"

QtDroidRelativeLayout::QtDroidRelativeLayout(QObject *parent) : QtDroidViewGroup(parent)
{
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
