#include "qtandroidbutton_p.h"

QtAndroidButton::QtAndroidButton(QtAndroidView *parent) : QtAndroidTextView(parent)
{
}

QAndroidJniObject QtAndroidButton::onCreate()
{
    return QAndroidJniObject("android/widget/Button",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidButton::onInflate(QAndroidJniObject &instance)
{
    QtAndroidTextView::onInflate(instance);
}
