#include "qqmlandroidswitch_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidSwitch::QQmlAndroidSwitch(QQmlAndroidView *parent) :
    QQmlAndroidCompoundButton(parent)
{
}

QAndroidJniObject QQmlAndroidSwitch::onCreate()
{
    return QAndroidJniObject("android/widget/Switch",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidSwitch::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidCompoundButton::onInflate(instance);
}

QT_END_NAMESPACE
