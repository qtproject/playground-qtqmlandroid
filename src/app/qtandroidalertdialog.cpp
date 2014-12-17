#include "qtandroidalertdialog_p.h"
#include "qtandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtAndroidAlertDialog::QtAndroidAlertDialog(QObject *parent) :
    QtAndroidDialog(parent)
{
}

QString QtAndroidAlertDialog::title() const
{
    return m_title;
}

void QtAndroidAlertDialog::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        QtAndroid::callTextMethod(instance(), "setTitle", title);
        emit titleChanged();
    }
}

QString QtAndroidAlertDialog::message() const
{
    return m_message;
}

void QtAndroidAlertDialog::setMessage(const QString &message)
{
    if (m_message != message) {
        m_message = message;
        QtAndroid::callTextMethod(instance(), "setMessage", message);
        emit messageChanged();
    }
}

QAndroidJniObject QtAndroidAlertDialog::onCreate()
{
    return QAndroidJniObject("android/app/AlertDialog",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidAlertDialog::onInflate(QAndroidJniObject& instance)
{
    QtAndroidDialog::onInflate(instance);

    if (!m_title.isNull())
        instance.callMethod<void>("setTitle", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_title).object());
    if (!m_message.isNull())
        instance.callMethod<void>("setMessage", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_message).object());
}

QT_END_NAMESPACE
