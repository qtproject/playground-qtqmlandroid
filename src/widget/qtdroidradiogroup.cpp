#include "qtdroidradiogroup_p.h"

QtDroidRadioGroup::QtDroidRadioGroup(QObject *parent) : QtDroidLinearLayout(parent)
{
}

QAndroidJniObject QtDroidRadioGroup::construct(jobject context)
{
    return QAndroidJniObject("android/widget/RadioGroup",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidRadioGroup::inflate(jobject context)
{
    QtDroidLinearLayout::inflate(context);
}
