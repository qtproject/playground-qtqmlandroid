#include "qtandroidwindow_p.h"
#include "qtandroidcontext_p.h"
#include "qtandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtAndroidWindow::QtAndroidWindow(QtAndroidContext *context) :
    QtAndroidContextual(context)
{
    setContext(context);
}

int QtAndroidWindow::statusBarColor() const
{
    if (m_statusBarColor.isNull())
        return 0; // TODO
    return m_statusBarColor.value();
}

void QtAndroidWindow::setStatusBarColor(int color)
{
    if (m_statusBarColor.isNull() || m_statusBarColor.value() != color) {
        m_statusBarColor = color;
        QtAndroid::callIntMethod(instance(), "setStatusBarColor", color);
        emit statusBarColorChanged();
    }
}

void QtAndroidWindow::onInflate(QAndroidJniObject &instance)
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
