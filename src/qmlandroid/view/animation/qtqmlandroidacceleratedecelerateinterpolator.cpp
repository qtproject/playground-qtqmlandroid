#include "qtqmlandroidacceleratedecelerateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidAccelerateDecelerateInterpolator::QQmlAndroidAccelerateDecelerateInterpolator(QObject *parent) :
    QQmlAndroidInterpolator(parent)
{
}

QAndroidJniObject QQmlAndroidAccelerateDecelerateInterpolator::onCreate()
{
    return QAndroidJniObject("android/view/animation/AccelerateDecelerateInterpolator");
}

QT_END_NAMESPACE
