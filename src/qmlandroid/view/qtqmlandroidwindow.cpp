#include "qtqmlandroidwindow_p.h"
#include "qtqmlandroidcontext_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidWindow::QtQmlAndroidWindow(QtQmlAndroidContext *context) :
    QtQmlAndroidContextual(context)
{
    setContext(context);
}

int QtQmlAndroidWindow::statusBarColor() const
{
    if (m_statusBarColor.isNull())
        return 0; // TODO
    return m_statusBarColor.value();
}

void QtQmlAndroidWindow::setStatusBarColor(int color)
{
    if (m_statusBarColor.isNull() || m_statusBarColor.value() != color) {
        m_statusBarColor = color;
        QtQmlAndroid::callIntMethod(instance(), "setStatusBarColor", color);
        emit statusBarColorChanged();
    }
}

void QtQmlAndroidWindow::onInflate(QAndroidJniObject &instance)
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
