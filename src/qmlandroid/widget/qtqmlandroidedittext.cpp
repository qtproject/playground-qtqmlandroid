#include "qtqmlandroidedittext_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidEditText::QtQmlAndroidEditText(QtQmlAndroidView *parent) :
    QtQmlAndroidTextView(parent)
{
}

QAndroidJniObject QtQmlAndroidEditText::onCreate()
{
    return QAndroidJniObject("android/widget/EditText",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidEditText::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidTextView::onInflate(instance);
}

QT_END_NAMESPACE
