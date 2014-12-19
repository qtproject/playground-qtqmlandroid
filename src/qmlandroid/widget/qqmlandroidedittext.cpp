#include "qqmlandroidedittext_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidEditText::QQmlAndroidEditText(QQmlAndroidView *parent) :
    QQmlAndroidTextView(parent)
{
}

QAndroidJniObject QQmlAndroidEditText::onCreate()
{
    return QAndroidJniObject("android/widget/EditText",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidEditText::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidTextView::onInflate(instance);
}

QT_END_NAMESPACE
