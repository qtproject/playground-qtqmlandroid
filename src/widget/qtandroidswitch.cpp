#include "qtandroidswitch_p.h"

QT_BEGIN_NAMESPACE

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

QT_END_NAMESPACE
