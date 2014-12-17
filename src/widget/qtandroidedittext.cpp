#include "qtandroidedittext_p.h"

QT_BEGIN_NAMESPACE

QtAndroidEditText::QtAndroidEditText(QtAndroidView *parent) :
    QtAndroidTextView(parent)
{
}

QAndroidJniObject QtAndroidEditText::onCreate()
{
    return QAndroidJniObject("android/widget/EditText",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidEditText::onInflate(QAndroidJniObject &instance)
{
    QtAndroidTextView::onInflate(instance);
}

QT_END_NAMESPACE
