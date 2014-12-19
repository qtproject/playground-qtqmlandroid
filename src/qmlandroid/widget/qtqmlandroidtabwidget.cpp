#include "qtqmlandroidtabwidget_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidTabWidget::QtQmlAndroidTabWidget(QtQmlAndroidView *parent) :
    QtQmlAndroidLinearLayout(parent)
{
    setIdentifier(16908307); // TODO: android.R.id.tabs
}

QAndroidJniObject QtQmlAndroidTabWidget::onCreate()
{
    return QAndroidJniObject("android/widget/TabWidget",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidTabWidget::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidLinearLayout::onInflate(instance);
}

QT_END_NAMESPACE
