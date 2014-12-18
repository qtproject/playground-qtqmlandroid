#include "qtandroidlinearinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidLinearInterpolator::QtAndroidLinearInterpolator(QObject *parent) :
    QtAndroidInterpolator(parent)
{
}

QAndroidJniObject QtAndroidLinearInterpolator::onCreate()
{
    return QAndroidJniObject("android/view/animation/LinearInterpolator");
}

void QtAndroidLinearInterpolator::onInflate(QAndroidJniObject &instance)
{
    QtAndroidInterpolator::onInflate(instance);
}

QT_END_NAMESPACE
