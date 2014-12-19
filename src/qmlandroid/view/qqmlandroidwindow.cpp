#include "qqmlandroidwindow_p.h"
#include "qqmlandroidcontext_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidWindow::QQmlAndroidWindow(QQmlAndroidContext *context) :
    QQmlAndroidContextual(context)
{
    setContext(context);
}

int QQmlAndroidWindow::statusBarColor() const
{
    if (m_statusBarColor.isNull())
        return 0; // TODO
    return m_statusBarColor.value();
}

void QQmlAndroidWindow::setStatusBarColor(int color)
{
    if (m_statusBarColor.isNull() || m_statusBarColor.value() != color) {
        m_statusBarColor = color;
        QtQmlAndroid::callIntMethod(instance(), "setStatusBarColor", color);
        emit statusBarColorChanged();
    }
}

void QQmlAndroidWindow::onInflate(QAndroidJniObject &instance)
{
    if (!m_statusBarColor.isNull()) {
        // TODO: WindowManager.LayoutParams.FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS
        instance.callMethod<void>("addFlags", "(I)V", 0x80000000);
        // TODO: WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS
        instance.callMethod<void>("clearFlags", "(I)V", 0x04000000);
        instance.callMethod<void>("setStatusBarColor", "(I)V", m_statusBarColor.value());
    }
}

QT_END_NAMESPACE
