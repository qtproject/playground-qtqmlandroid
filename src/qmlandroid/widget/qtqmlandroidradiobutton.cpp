#include "qtqmlandroidradiobutton_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidRadioButton::QtQmlAndroidRadioButton(QtQmlAndroidView *parent) :
    QtQmlAndroidCompoundButton(parent)
{
}

QAndroidJniObject QtQmlAndroidRadioButton::onCreate()
{
    return QAndroidJniObject("android/widget/RadioButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidRadioButton::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidCompoundButton::onInflate(instance);
}

QT_END_NAMESPACE
