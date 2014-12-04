#include "qtdroidtabwidget_p.h"

QtDroidTabWidget::QtDroidTabWidget(QtDroidView *parent) : QtDroidLinearLayout(parent)
{
    setIdentifier(16908307); // TODO: android.R.id.tabs
}

QAndroidJniObject QtDroidTabWidget::construct()
{
    return QAndroidJniObject("android/widget/TabWidget",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidTabWidget::inflate()
{
    QtDroidLinearLayout::inflate();
}
