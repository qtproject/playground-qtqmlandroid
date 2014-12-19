#include "qtqmlandroidtabwidget_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidTabWidget::QQmlAndroidTabWidget(QQmlAndroidView *parent) :
    QQmlAndroidLinearLayout(parent)
{
    setIdentifier(16908307); // TODO: android.R.id.tabs
}

QAndroidJniObject QQmlAndroidTabWidget::onCreate()
{
    return QAndroidJniObject("android/widget/TabWidget",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidTabWidget::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidLinearLayout::onInflate(instance);
}

QT_END_NAMESPACE
