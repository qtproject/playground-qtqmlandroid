#include "qtandroidbounceinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidBounceInterpolator::QtAndroidBounceInterpolator(QObject *parent) :
    QtAndroidInterpolator(parent)
{
}

QAndroidJniObject QtAndroidBounceInterpolator::onCreate()
{
    return QAndroidJniObject("android/view/animation/BounceInterpolator");
}

QT_END_NAMESPACE
