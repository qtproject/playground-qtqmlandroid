#include "qtandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidInterpolator::QtAndroidInterpolator(QObject *parent) :
    QtAndroidObject(parent)
{
}

QAndroidJniObject QtAndroidInterpolator::onCreate()
{
    return QAndroidJniObject();
}

void QtAndroidInterpolator::onInflate(QAndroidJniObject &instance)
{
    QtAndroidObject::onInflate(instance);
}

QT_END_NAMESPACE
