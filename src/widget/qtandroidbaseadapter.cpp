#include "qtandroidbaseadapter_p.h"
#include "qtandroidcontext_p.h"

QtAndroidBaseAdapter::QtAndroidBaseAdapter(QObject *parent) :
    QtAndroidObject(parent), m_context(0)
{
}

QAndroidJniObject QtAndroidBaseAdapter::ctx() const
{
    if (!m_context)
        return QAndroidJniObject();
    return m_context->instance();
}

QtAndroidContext *QtAndroidBaseAdapter::context() const
{
    return m_context;
}

void QtAndroidBaseAdapter::setContext(QtAndroidContext *context)
{
    if (m_context != context) {
        m_context = context;
        emit contextChanged();
    }
}

QAndroidJniObject QtAndroidBaseAdapter::onCreate()
{
    return QAndroidJniObject("android/widget/BaseAdapter");
}

void QtAndroidBaseAdapter::onInflate(QAndroidJniObject &instance)
{
    QtAndroidObject::onInflate(instance);
}
