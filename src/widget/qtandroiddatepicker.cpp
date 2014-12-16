#include "qtandroiddatepicker_p.h"

QtAndroidDatePicker::QtAndroidDatePicker(QtAndroidView *parent) :
    QtAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtAndroidDatePicker::onCreate()
{
    return QAndroidJniObject("android/widget/DatePicker",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidDatePicker::onInflate(QAndroidJniObject &instance)
{
    QtAndroidFrameLayout::onInflate(instance);
}
