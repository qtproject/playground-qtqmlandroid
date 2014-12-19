#include "qtqmlandroidcheckbox_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidCheckBox::QtQmlAndroidCheckBox(QtQmlAndroidView *parent) :
    QtQmlAndroidCompoundButton(parent)
{
}

QAndroidJniObject QtQmlAndroidCheckBox::onCreate()
{
    return QAndroidJniObject("android/widget/CheckBox",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidCheckBox::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidCompoundButton::onInflate(instance);
}

QT_END_NAMESPACE
