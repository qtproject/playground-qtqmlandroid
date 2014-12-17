#include "qtandroiddialog_p.h"
#include "qtandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtAndroidDialog::QtAndroidDialog(QObject *parent) :
    QtAndroidContextual(parent)
{
}

void QtAndroidDialog::cancel()
{
    QtAndroid::callVoidMethod(instance(), "cancel");
}

void QtAndroidDialog::dismiss()
{
    QtAndroid::callVoidMethod(instance(), "dismiss");
}

void QtAndroidDialog::hide()
{
    QtAndroid::callVoidMethod(instance(), "hide");
}

void QtAndroidDialog::show()
{
    QtAndroid::callVoidMethod(instance(), "show");
}

QAndroidJniObject QtAndroidDialog::onCreate()
{
    return QAndroidJniObject("android/app/Dialog",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidDialog::onInflate(QAndroidJniObject& instance)
{
    QtAndroidContextual::onInflate(instance);
}

QT_END_NAMESPACE
