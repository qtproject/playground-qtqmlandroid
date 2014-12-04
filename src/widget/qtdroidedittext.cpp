#include "qtdroidedittext_p.h"

QtDroidEditText::QtDroidEditText(QtDroidView *parent) : QtDroidTextView(parent)
{
}

QAndroidJniObject QtDroidEditText::construct()
{
    return QAndroidJniObject("android/widget/EditText",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidEditText::inflate()
{
    QtDroidTextView::inflate();
}
