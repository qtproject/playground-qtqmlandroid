#include "qtqmlandroidtoast_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qtqmlandroidview_p.h"
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

QtQmlAndroidToast::QtQmlAndroidToast(QObject *parent) :
    QtQmlAndroidObject(parent)
{
}

QString QtQmlAndroidToast::text() const
{
    return m_text;
}

void QtQmlAndroidToast::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
        emit textChanged();
    }
}

int QtQmlAndroidToast::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QtQmlAndroidToast::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

void QtQmlAndroidToast::show()
{
    QtQmlAndroidView *view = qobject_cast<QtQmlAndroidView *>(parent());
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
            toast.callMethod<void>("setGravity", "(I)V", m_gravity.value());

        toast.callMethod<void>("show");
    });
}

void QtQmlAndroidToast::cancel()
{
    QtQmlAndroid::callVoidMethod(instance(), "cancel");
}

QT_END_NAMESPACE
