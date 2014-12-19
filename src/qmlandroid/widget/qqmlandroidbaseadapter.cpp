#include "qqmlandroidbaseadapter_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidBaseAdapter::QQmlAndroidBaseAdapter(QObject *parent) :
    QQmlAndroidContextual(parent)
{
}

QAndroidJniObject QQmlAndroidBaseAdapter::onCreate()
{
    return QAndroidJniObject("android/widget/BaseAdapter");
}

void QQmlAndroidBaseAdapter::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidContextual::onInflate(instance);
}

QT_END_NAMESPACE
