#include "qtandroidtimepicker_p.h"

QT_BEGIN_NAMESPACE

QtAndroidTimePicker::QtAndroidTimePicker(QtAndroidView *parent) :
    QtAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtAndroidTimePicker::onCreate()
{
    return QAndroidJniObject("android/widget/TimePicker",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidTimePicker::onInflate(QAndroidJniObject &instance)
{
    QtAndroidFrameLayout::onInflate(instance);
}

QT_END_NAMESPACE
