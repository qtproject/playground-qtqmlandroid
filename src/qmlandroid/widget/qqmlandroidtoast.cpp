#include "qqmlandroidtoast_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qqmlandroidview_p.h"
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

QQmlAndroidToast::QQmlAndroidToast(QObject *parent) :
    QQmlAndroidObject(parent)
{
}

QString QQmlAndroidToast::text() const
{
    return m_text;
}

void QQmlAndroidToast::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
        emit textChanged();
    }
}

int QQmlAndroidToast::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity;
}

void QQmlAndroidToast::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

void QQmlAndroidToast::show()
{
    QQmlAndroidView *view = qobject_cast<QQmlAndroidView *>(parent());
    if (!view) {
        qWarning() << "Toast must be in a view.";
        return;
    }

    QAndroidJniObject ctx = view->ctx();
    if (!ctx.isValid()) {
        qWarning() << "Toast is not ready - no context.";
        return;
    }

    QtQmlAndroid::callFunction([=]() {
        QAndroidJniObject toast;
        if (!m_text.isNull()) {
            toast = QAndroidJniObject::callStaticObjectMethod("android/widget/Toast",
                                                              "makeText",
                                                              "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;",
                                                              ctx.object(),
                                                              QAndroidJniObject::fromString(m_text).object(),
                                                              0); // TODO: LENGTH_SHORT (0), LENGTH_LONG (1)
        } else {
            toast = QAndroidJniObject("android/widget/Toast",
                                      "(Landroid/content/Context;)V",
                                      ctx.object());
        }
        inflate(toast);

        if (!m_gravity.isNull())
            toast.callMethod<void>("setGravity", "(I)V", m_gravity);

        toast.callMethod<void>("show");
    });
}

void QQmlAndroidToast::cancel()
{
    QtQmlAndroid::callVoidMethod(instance(), "cancel");
}

QT_END_NAMESPACE
