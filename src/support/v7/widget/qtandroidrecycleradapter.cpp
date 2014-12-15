#include "qtandroidrecycleradapter_p.h"

QtAndroidRecyclerAdapter::QtAndroidRecyclerAdapter(QObject *parent) :
    QtAndroidContextual(parent)
{
}

QStringList QtAndroidRecyclerAdapter::array() const
{
    return m_array;
}

void QtAndroidRecyclerAdapter::setArray(const QStringList &array)
{
    if (m_array != array) {
        m_array = array;
        emit arrayChanged();
    }
}

QAndroidJniObject QtAndroidRecyclerAdapter::onCreate()
{
    return QAndroidJniObject("qt/android/support/v7/widget/QtRecyclerAdapter");
}

void QtAndroidRecyclerAdapter::onInflate(QAndroidJniObject &instance)
{
    QtAndroidContextual::onInflate(instance);

    foreach (const QString &str, m_array)
        instance.callMethod<void>("add", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(str).object());
}
