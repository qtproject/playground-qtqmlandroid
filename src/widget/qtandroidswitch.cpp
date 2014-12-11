#include "qtandroidswitch_p.h"

QtAndroidSwitch::QtAndroidSwitch(QtAndroidView *parent) : QtAndroidCompoundButton(parent)
{
}

QAndroidJniObject QtAndroidSwitch::construct()
{
    return QAndroidJniObject("android/widget/Switch",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidSwitch::inflate()
{
    QtAndroidCompoundButton::inflate();
}
