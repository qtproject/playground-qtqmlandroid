#include "qtdroidcheckbox_p.h"

QtDroidCheckBox::QtDroidCheckBox(QtDroidView *parent) : QtDroidCompoundButton(parent)
{
}

QAndroidJniObject QtDroidCheckBox::construct()
{
    return QAndroidJniObject("android/widget/CheckBox",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidCheckBox::inflate()
{
    QtDroidCompoundButton::inflate();
}
