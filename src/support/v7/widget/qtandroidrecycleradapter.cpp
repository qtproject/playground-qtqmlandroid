#include "qtandroidrecycleradapter_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidRecyclerAdapter::QtAndroidRecyclerAdapter(QObject *parent) :
    QtAndroidContextual(parent), m_count(0)
{
}

int QtAndroidRecyclerAdapter::count() const
{
    return m_count;
}

void QtAndroidRecyclerAdapter::setCount(int count)
{
    if (m_count != count) {
        m_count = count;
        QtAndroid::callIntMethod(instance(), "setCount", count);
        emit countChanged();
    }
}

QAndroidJniObject QtAndroidRecyclerAdapter::onCreate()
{
    return QAndroidJniObject("qt/android/support/v7/widget/QtRecyclerAdapter",
                             "(IJ)V",
                             m_count,
                             reinterpret_cast<jlong>(this));
}

void QtAndroidRecyclerAdapter::onInflate(QAndroidJniObject &instance)
{
    QtAndroidContextual::onInflate(instance);

    if (m_count > 0)
        instance.callMethod<void>("setCount", "(I)V", m_count);
}
