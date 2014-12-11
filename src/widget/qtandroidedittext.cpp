#include "qtandroidedittext_p.h"

QtAndroidEditText::QtAndroidEditText(QtAndroidView *parent) : QtAndroidTextView(parent)
{
}

QAndroidJniObject QtAndroidEditText::construct()
{
    return QAndroidJniObject("android/widget/EditText",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidEditText::inflate()
{
    QtAndroidTextView::inflate();
}
