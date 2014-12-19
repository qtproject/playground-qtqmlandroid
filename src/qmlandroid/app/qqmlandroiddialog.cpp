#include "qqmlandroiddialog_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidDialog::QQmlAndroidDialog(QObject *parent) :
    QQmlAndroidContextual(parent)
{
}

void QQmlAndroidDialog::cancel()
{
    QtQmlAndroid::callVoidMethod(instance(), "cancel");
}

void QQmlAndroidDialog::dismiss()
{
    QtQmlAndroid::callVoidMethod(instance(), "dismiss");
}

void QQmlAndroidDialog::hide()
{
    QtQmlAndroid::callVoidMethod(instance(), "hide");
}

void QQmlAndroidDialog::show()
{
    QtQmlAndroid::callVoidMethod(instance(), "show");
}

QAndroidJniObject QQmlAndroidDialog::onCreate()
{
    return QAndroidJniObject("android/app/Dialog",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidDialog::onInflate(QAndroidJniObject& instance)
{
    QQmlAndroidContextual::onInflate(instance);
}

QT_END_NAMESPACE
