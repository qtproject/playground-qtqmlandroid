#include "qtdroidswitch_p.h"

QtDroidSwitch::QtDroidSwitch(QObject *parent) : QtDroidCompoundButton(parent)
{
}

QAndroidJniObject QtDroidSwitch::construct(jobject context)
{
    return QAndroidJniObject("android/widget/Switch",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidSwitch::inflate(jobject context)
{
    QtDroidCompoundButton::inflate(context);
}
