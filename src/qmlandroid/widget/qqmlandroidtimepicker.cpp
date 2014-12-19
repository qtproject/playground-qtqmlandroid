#include "qqmlandroidtimepicker_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidTimePicker::QQmlAndroidTimePicker(QQmlAndroidView *parent) :
    QQmlAndroidFrameLayout(parent)
{
}

QAndroidJniObject QQmlAndroidTimePicker::onCreate()
{
    return QAndroidJniObject("android/widget/TimePicker",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidTimePicker::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidFrameLayout::onInflate(instance);
}

QT_END_NAMESPACE
