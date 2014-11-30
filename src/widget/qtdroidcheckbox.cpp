#include "qtdroidcheckbox_p.h"

QtDroidCheckBox::QtDroidCheckBox(QObject *parent) : QtDroidCompoundButton(parent)
{
}

QAndroidJniObject QtDroidCheckBox::construct(jobject context)
{
    return QAndroidJniObject("android/widget/CheckBox",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidCheckBox::inflate(jobject context)
{
    QtDroidCompoundButton::inflate(context);
}
