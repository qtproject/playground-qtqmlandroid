#include "qtqmlandroidalertdialog_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidAlertDialog::QQmlAndroidAlertDialog(QObject *parent) :
    QQmlAndroidDialog(parent)
{
}

QString QQmlAndroidAlertDialog::title() const
{
    return m_title;
}

void QQmlAndroidAlertDialog::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        QtQmlAndroid::callTextMethod(instance(), "setTitle", title);
        emit titleChanged();
    }
}

QString QQmlAndroidAlertDialog::message() const
{
    return m_message;
}

void QQmlAndroidAlertDialog::setMessage(const QString &message)
{
    if (m_message != message) {
        m_message = message;
        QtQmlAndroid::callTextMethod(instance(), "setMessage", message);
        emit messageChanged();
    }
}

QAndroidJniObject QQmlAndroidAlertDialog::onCreate()
{
    return QAndroidJniObject("android/app/AlertDialog",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidAlertDialog::onInflate(QAndroidJniObject& instance)
{
    QQmlAndroidDialog::onInflate(instance);

    if (!m_title.isNull())
        instance.callMethod<void>("setTitle", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_title).object());
    if (!m_message.isNull())
        instance.callMethod<void>("setMessage", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_message).object());
}

QT_END_NAMESPACE
