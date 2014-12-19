#include "qtqmlandroiddialog_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidDialog::QtQmlAndroidDialog(QObject *parent) :
    QtQmlAndroidContextual(parent)
{
}

void QtQmlAndroidDialog::cancel()
{
    QtQmlAndroid::callVoidMethod(instance(), "cancel");
}

void QtQmlAndroidDialog::dismiss()
{
    QtQmlAndroid::callVoidMethod(instance(), "dismiss");
}

void QtQmlAndroidDialog::hide()
{
    QtQmlAndroid::callVoidMethod(instance(), "hide");
}

void QtQmlAndroidDialog::show()
{
    QtQmlAndroid::callVoidMethod(instance(), "show");
}

QAndroidJniObject QtQmlAndroidDialog::onCreate()
{
    return QAndroidJniObject("android/app/Dialog",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidDialog::onInflate(QAndroidJniObject& instance)
{
    QtQmlAndroidContextual::onInflate(instance);
}

QT_END_NAMESPACE
