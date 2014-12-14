#include "qtandroidspinner_p.h"

QtAndroidSpinner::QtAndroidSpinner(QtAndroidView *parent) : QtAndroidAdapterView(parent)
{
}

QAndroidJniObject QtAndroidSpinner::onCreate()
{
    return QAndroidJniObject("android/widget/Spinner",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidSpinner::onInflate()
{
    QtAndroidAdapterView::onInflate();
}
