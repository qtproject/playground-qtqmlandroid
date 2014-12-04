#include "qtdroidradiobutton_p.h"

QtDroidRadioButton::QtDroidRadioButton(QtDroidView *parent) : QtDroidCompoundButton(parent)
{
}

QAndroidJniObject QtDroidRadioButton::construct()
{
    return QAndroidJniObject("android/widget/RadioButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidRadioButton::inflate()
{
    QtDroidCompoundButton::inflate();
}
