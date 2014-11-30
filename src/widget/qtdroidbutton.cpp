#include "qtdroidbutton_p.h"

QtDroidButton::QtDroidButton(QObject *parent) : QtDroidTextView(parent)
{
}

QAndroidJniObject QtDroidButton::construct(jobject context)
{
    return QAndroidJniObject("android/widget/Button",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidButton::inflate(jobject context)
{
    QtDroidTextView::inflate(context);
}
