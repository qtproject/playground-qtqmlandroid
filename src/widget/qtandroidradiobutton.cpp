#include "qtandroidradiobutton_p.h"

QtAndroidRadioButton::QtAndroidRadioButton(QtAndroidView *parent) :
    QtAndroidCompoundButton(parent)
{
}

QAndroidJniObject QtAndroidRadioButton::onCreate()
{
    return QAndroidJniObject("android/widget/RadioButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidRadioButton::onInflate(QAndroidJniObject &instance)
{
    QtAndroidCompoundButton::onInflate(instance);
}
