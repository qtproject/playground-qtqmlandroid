#include "qtandroidcheckbox_p.h"

QT_BEGIN_NAMESPACE

QtAndroidCheckBox::QtAndroidCheckBox(QtAndroidView *parent) :
    QtAndroidCompoundButton(parent)
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

QT_END_NAMESPACE
