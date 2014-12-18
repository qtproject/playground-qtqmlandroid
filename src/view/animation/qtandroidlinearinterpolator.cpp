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

QT_END_NAMESPACE
