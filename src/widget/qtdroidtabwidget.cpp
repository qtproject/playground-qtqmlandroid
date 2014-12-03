#include "qtdroidtabwidget_p.h"

QtDroidTabWidget::QtDroidTabWidget(QtDroidView *parent) : QtDroidLinearLayout(parent)
{
    setIdentifier(16908307); // TODO: android.R.id.tabs
}

QAndroidJniObject QtDroidTabWidget::construct(jobject context)
{
    return QAndroidJniObject("android/widget/TabWidget",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidTabWidget::inflate(jobject context)
{
    QtDroidLinearLayout::inflate(context);
}
