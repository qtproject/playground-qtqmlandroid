#include "qtandroidaccelerateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidAccelerateInterpolator::QtAndroidAccelerateInterpolator(QObject *parent) :
    QtAndroidInterpolator(parent)
{
}

QAndroidJniObject QtAndroidAccelerateInterpolator::onCreate()
{
    return QAndroidJniObject("android/view/animation/AccelerateInterpolator");
}

void QtAndroidAccelerateInterpolator::onInflate(QAndroidJniObject &instance)
{
    QtAndroidInterpolator::onInflate(instance);
}

QT_END_NAMESPACE
