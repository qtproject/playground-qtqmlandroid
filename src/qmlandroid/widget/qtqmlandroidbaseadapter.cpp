#include "qtqmlandroidbaseadapter_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidBaseAdapter::QtQmlAndroidBaseAdapter(QObject *parent) :
    QtQmlAndroidContextual(parent)
{
}

QAndroidJniObject QtQmlAndroidBaseAdapter::onCreate()
{
    return QAndroidJniObject("android/widget/BaseAdapter");
}

void QtQmlAndroidBaseAdapter::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidContextual::onInflate(instance);
}

QT_END_NAMESPACE
