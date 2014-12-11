#include "qtdroidspinner_p.h"

QtAndroidSpinner::QtAndroidSpinner(QtAndroidView *parent) : QtAndroidAdapterView(parent)
{
}

QAndroidJniObject QtAndroidSpinner::construct()
{
    return QAndroidJniObject("android/widget/Spinner",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidSpinner::inflate()
{
    QtAndroidAdapterView::inflate();
}
