#include "qqmlandroidbutton_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidButton::QQmlAndroidButton(QQmlAndroidView *parent) :
    QQmlAndroidTextView(parent)
{
}

QAndroidJniObject QQmlAndroidButton::onCreate()
{
    return QAndroidJniObject("android/widget/Button",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidButton::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidTextView::onInflate(instance);
}

QT_END_NAMESPACE
