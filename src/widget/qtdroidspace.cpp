#include "qtdroidspace_p.h"

QtDroidSpace::QtDroidSpace(QtDroidView *parent) : QtDroidView(parent)
{
}

QAndroidJniObject QtDroidSpace::construct()
{
    return QAndroidJniObject("android/widget/Space",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidSpace::inflate()
{
    QtDroidView::inflate();
}
