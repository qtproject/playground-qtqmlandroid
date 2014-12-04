#include "qtdroidbutton_p.h"

QtDroidButton::QtDroidButton(QtDroidView *parent) : QtDroidTextView(parent)
{
}

QAndroidJniObject QtDroidButton::construct()
{
    return QAndroidJniObject("android/widget/Button",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidButton::inflate()
{
    QtDroidTextView::inflate();
}
