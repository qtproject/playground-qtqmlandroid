#include "qtqmlandroiddatepicker_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidDatePicker::QQmlAndroidDatePicker(QQmlAndroidView *parent) :
    QQmlAndroidFrameLayout(parent)
{
}

QAndroidJniObject QQmlAndroidDatePicker::onCreate()
{
    return QAndroidJniObject("android/widget/DatePicker",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidDatePicker::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidFrameLayout::onInflate(instance);
}

QT_END_NAMESPACE
