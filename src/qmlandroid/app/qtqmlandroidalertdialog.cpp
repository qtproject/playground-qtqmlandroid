#include "qtqmlandroidalertdialog_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidAlertDialog::QtQmlAndroidAlertDialog(QObject *parent) :
    QtQmlAndroidDialog(parent)
{
}

QString QtQmlAndroidAlertDialog::title() const
{
    return m_title;
}

void QtQmlAndroidAlertDialog::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        QtQmlAndroid::callTextMethod(instance(), "setTitle", title);
        emit titleChanged();
    }
}

QString QtQmlAndroidAlertDialog::message() const
{
    return m_message;
}

void QtQmlAndroidAlertDialog::setMessage(const QString &message)
{
    if (m_message != message) {
        m_message = message;
        QtQmlAndroid::callTextMethod(instance(), "setMessage", message);
        emit messageChanged();
    }
}

QAndroidJniObject QtQmlAndroidAlertDialog::onCreate()
{
    return QAndroidJniObject("android/app/AlertDialog",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidAlertDialog::onInflate(QAndroidJniObject& instance)
{
    QtQmlAndroidDialog::onInflate(instance);

    if (!m_title.isNull())
        instance.callMethod<void>("setTitle", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_title).object());
    if (!m_message.isNull())
        instance.callMethod<void>("setMessage", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_message).object());
}

QT_END_NAMESPACE
