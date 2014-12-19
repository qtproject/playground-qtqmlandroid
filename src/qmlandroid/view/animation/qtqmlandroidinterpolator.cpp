#include "qtqmlandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidInterpolator::QQmlAndroidInterpolator(QObject *parent) :
    QQmlAndroidObject(parent)
{
}

QAndroidJniObject QQmlAndroidInterpolator::onCreate()
{
    return QAndroidJniObject();
}

QT_END_NAMESPACE
