#include "qtandroidradiobutton_p.h"

QtAndroidRadioButton::QtAndroidRadioButton(QtAndroidView *parent) : QtAndroidCompoundButton(parent)
{
}

QAndroidJniObject QtAndroidRadioButton::construct()
{
    return QAndroidJniObject("android/widget/RadioButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidRadioButton::inflate()
{
    QtAndroidCompoundButton::inflate();
}
