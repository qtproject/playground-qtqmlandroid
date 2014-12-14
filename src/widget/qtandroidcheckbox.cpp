#include "qtandroidcheckbox_p.h"

QtAndroidCheckBox::QtAndroidCheckBox(QtAndroidView *parent) : QtAndroidCompoundButton(parent)
{
}

QAndroidJniObject QtAndroidCheckBox::onCreate()
{
    return QAndroidJniObject("android/widget/CheckBox",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidCheckBox::onInflate(QAndroidJniObject &instance)
{
    QtAndroidCompoundButton::onInflate(instance);
}
