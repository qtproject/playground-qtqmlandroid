#include "qtdroidspace_p.h"

QtDroidSpace::QtDroidSpace(QtDroidView *parent) : QtDroidView(parent)
{
}

QAndroidJniObject QtDroidSpace::construct(jobject context)
{
    return QAndroidJniObject("android/widget/Space",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidSpace::inflate(jobject context)
{
    QtDroidView::inflate(context);
}
