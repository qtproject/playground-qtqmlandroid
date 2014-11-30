#include "qtdroidedittext_p.h"

QtDroidEditText::QtDroidEditText(QObject *parent) : QtDroidTextView(parent)
{
}

QAndroidJniObject QtDroidEditText::construct(jobject context)
{
    return QAndroidJniObject("android/widget/EditText",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidEditText::inflate(jobject context)
{
    QtDroidTextView::inflate(context);
}
