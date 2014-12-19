#include "qtqmlandroidswitch_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidSwitch::QtQmlAndroidSwitch(QtQmlAndroidView *parent) :
    QtQmlAndroidCompoundButton(parent)
{
}

QAndroidJniObject QtQmlAndroidSwitch::onCreate()
{
    return QAndroidJniObject("android/widget/Switch",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidSwitch::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidCompoundButton::onInflate(instance);
}

QT_END_NAMESPACE
