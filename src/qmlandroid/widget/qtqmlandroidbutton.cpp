#include "qtqmlandroidbutton_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidButton::QtQmlAndroidButton(QtQmlAndroidView *parent) :
    QtQmlAndroidTextView(parent)
{
}

QAndroidJniObject QtQmlAndroidButton::onCreate()
{
    return QAndroidJniObject("android/widget/Button",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidButton::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidTextView::onInflate(instance);
}

QT_END_NAMESPACE
