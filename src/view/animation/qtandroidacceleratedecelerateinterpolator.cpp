#include "qtandroidacceleratedecelerateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidAccelerateDecelerateInterpolator::QtAndroidAccelerateDecelerateInterpolator(QObject *parent) :
    QtAndroidInterpolator(parent)
{
}

QAndroidJniObject QtAndroidAccelerateDecelerateInterpolator::onCreate()
{
    return QAndroidJniObject("android/view/animation/AccelerateDecelerateInterpolator");
}

void QtAndroidAccelerateDecelerateInterpolator::onInflate(QAndroidJniObject &instance)
{
    QtAndroidInterpolator::onInflate(instance);
}

QT_END_NAMESPACE
