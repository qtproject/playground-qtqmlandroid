#include "qtandroidbaseadapter_p.h"

QT_BEGIN_NAMESPACE

QtAndroidBaseAdapter::QtAndroidBaseAdapter(QObject *parent) :
    QtAndroidContextual(parent)
{
}

QAndroidJniObject QtAndroidBaseAdapter::onCreate()
{
    return QAndroidJniObject("android/widget/BaseAdapter");
}

void QtAndroidBaseAdapter::onInflate(QAndroidJniObject &instance)
{
    QtAndroidContextual::onInflate(instance);
}

QT_END_NAMESPACE
