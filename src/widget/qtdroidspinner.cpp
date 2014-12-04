#include "qtdroidspinner_p.h"

QtDroidSpinner::QtDroidSpinner(QtDroidView *parent) : QtDroidAdapterView(parent)
{
}

QAndroidJniObject QtDroidSpinner::construct()
{
    return QAndroidJniObject("android/widget/Spinner",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidSpinner::inflate()
{
    QtDroidAdapterView::inflate();
}
