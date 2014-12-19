#include "qqmlandroidradiobutton_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidRadioButton::QQmlAndroidRadioButton(QQmlAndroidView *parent) :
    QQmlAndroidCompoundButton(parent)
{
}

QAndroidJniObject QQmlAndroidRadioButton::onCreate()
{
    return QAndroidJniObject("android/widget/RadioButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidRadioButton::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidCompoundButton::onInflate(instance);
}

QT_END_NAMESPACE
