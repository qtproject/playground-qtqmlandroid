#include "qtandroiddialog_p.h"
#include "qtandroidcontext_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidDialog::QtAndroidDialog(QObject *parent) :
    QtAndroidObject(parent), m_context(0)
{
}

QAndroidJniObject QtAndroidDialog::ctx() const
{
    if (!m_context)
        return QAndroidJniObject();
    return m_context->instance();
}

QtAndroidContext *QtAndroidDialog::context() const
{
    return m_context;
}

void QtAndroidDialog::setContext(QtAndroidContext *context)
{
    if (m_context != context) {
        m_context = context;
        emit contextChanged();
    }
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
    QtAndroidObject::onInflate(instance);
}
