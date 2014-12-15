#include "qtandroidswitch_p.h"

QtAndroidSwitch::QtAndroidSwitch(QtAndroidView *parent) :
    QtAndroidCompoundButton(parent)
{
}

QAndroidJniObject QtAndroidSwitch::onCreate()
{
    return QAndroidJniObject("android/widget/Switch",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidSwitch::onInflate(QAndroidJniObject &instance)
{
    QtAndroidCompoundButton::onInflate(instance);
}
