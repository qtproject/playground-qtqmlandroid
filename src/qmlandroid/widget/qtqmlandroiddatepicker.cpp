#include "qtqmlandroiddatepicker_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidDatePicker::QtQmlAndroidDatePicker(QtQmlAndroidView *parent) :
    QtQmlAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtQmlAndroidDatePicker::onCreate()
{
    return QAndroidJniObject("android/widget/DatePicker",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidDatePicker::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidFrameLayout::onInflate(instance);
}

QT_END_NAMESPACE
