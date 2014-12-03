#include "qtdroidspinner_p.h"

QtDroidSpinner::QtDroidSpinner(QtDroidView *parent) : QtDroidAdapterView(parent)
{
}

QAndroidJniObject QtDroidSpinner::construct(jobject context)
{
    return QAndroidJniObject("android/widget/Spinner",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidSpinner::inflate(jobject context)
{
    QtDroidAdapterView::inflate(context);
}
