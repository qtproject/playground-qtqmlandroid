#include "qtdroidspace_p.h"

QtAndroidSpace::QtAndroidSpace(QtAndroidView *parent) : QtAndroidView(parent)
{
}

QAndroidJniObject QtAndroidSpace::construct()
{
    return QAndroidJniObject("android/widget/Space",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidSpace::inflate()
{
    QtAndroidView::inflate();
}
