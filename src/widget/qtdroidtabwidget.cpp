#include "qtdroidtabwidget_p.h"

QtAndroidTabWidget::QtAndroidTabWidget(QtAndroidView *parent) : QtAndroidLinearLayout(parent)
{
    setIdentifier(16908307); // TODO: android.R.id.tabs
}

QAndroidJniObject QtAndroidTabWidget::construct()
{
    return QAndroidJniObject("android/widget/TabWidget",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidTabWidget::inflate()
{
    QtAndroidLinearLayout::inflate();
}
