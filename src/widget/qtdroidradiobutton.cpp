#include "qtdroidradiobutton_p.h"

QtDroidRadioButton::QtDroidRadioButton(QtDroidView *parent) : QtDroidCompoundButton(parent)
{
}

QAndroidJniObject QtDroidRadioButton::construct(jobject context)
{
    return QAndroidJniObject("android/widget/RadioButton",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidRadioButton::inflate(jobject context)
{
    QtDroidCompoundButton::inflate(context);
}
