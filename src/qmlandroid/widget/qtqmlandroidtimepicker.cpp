#include "qtqmlandroidtimepicker_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidTimePicker::QtQmlAndroidTimePicker(QtQmlAndroidView *parent) :
    QtQmlAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtQmlAndroidTimePicker::onCreate()
{
    return QAndroidJniObject("android/widget/TimePicker",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidTimePicker::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidFrameLayout::onInflate(instance);
}

QT_END_NAMESPACE
