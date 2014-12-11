#include "qtdroidcheckbox_p.h"

QtAndroidCheckBox::QtAndroidCheckBox(QtAndroidView *parent) : QtAndroidCompoundButton(parent)
{
}

QAndroidJniObject QtAndroidCheckBox::construct()
{
    return QAndroidJniObject("android/widget/CheckBox",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidCheckBox::inflate()
{
    QtAndroidCompoundButton::inflate();
}
