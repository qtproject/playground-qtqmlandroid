#include "qtandroidbutton_p.h"

QtAndroidButton::QtAndroidButton(QtAndroidView *parent) : QtAndroidTextView(parent)
{
}

QAndroidJniObject QtAndroidButton::construct()
{
    return QAndroidJniObject("android/widget/Button",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidButton::inflate()
{
    QtAndroidTextView::inflate();
}
