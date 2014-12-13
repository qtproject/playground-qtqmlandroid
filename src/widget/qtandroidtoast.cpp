#include "qtandroidtoast_p.h"
#include "qtandroidfunctions_p.h"
#include "qtandroidview_p.h"
#include <QtCore/qdebug.h>

QtAndroidToast::QtAndroidToast(QObject *parent) :
    QtAndroidObject(parent)
{
}

QString QtAndroidToast::text() const
{
    return m_text;
}

void QtAndroidToast::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
        emit textChanged();
    }
}

int QtAndroidToast::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QtAndroidToast::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

void QtAndroidToast::show()
{
    QtAndroidView *view = qobject_cast<QtAndroidView *>(parent());
    if (!view) {
        qWarning() << "Toast must be in a view.";
        return;
    }

    QAndroidJniObject ctx = view->ctx();
    if (!ctx.isValid()) {
        qWarning() << "Toast is not ready - no context.";
        return;
    }

    QtAndroid::callFunction([=]() {
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
        setInstance(toast);

        if (!m_gravity.isNull())
            toast.callMethod<void>("setGravity", "(I)V", m_gravity.value());

        toast.callMethod<void>("show");
    });
}

void QtAndroidToast::cancel()
{
    QtAndroid::callVoidMethod(instance(), "cancel");
}
