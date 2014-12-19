#include "qqmlandroidcheckbox_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidCheckBox::QQmlAndroidCheckBox(QQmlAndroidView *parent) :
    QQmlAndroidCompoundButton(parent)
{
}

QAndroidJniObject QQmlAndroidCheckBox::onCreate()
{
    return QAndroidJniObject("android/widget/CheckBox",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidCheckBox::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidCompoundButton::onInflate(instance);
}

QT_END_NAMESPACE
