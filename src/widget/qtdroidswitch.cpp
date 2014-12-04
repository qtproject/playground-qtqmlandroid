#include "qtdroidswitch_p.h"

QtDroidSwitch::QtDroidSwitch(QtDroidView *parent) : QtDroidCompoundButton(parent)
{
}

QAndroidJniObject QtDroidSwitch::construct()
{
    return QAndroidJniObject("android/widget/Switch",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidSwitch::inflate()
{
    QtDroidCompoundButton::inflate();
}
