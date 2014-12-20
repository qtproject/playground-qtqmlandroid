#include "qqmlandroidbounceinterpolator_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidBounceInterpolator::QQmlAndroidBounceInterpolator(QObject *parent) :
    QQmlAndroidInterpolator(parent)
{
}

QAndroidJniObject QQmlAndroidBounceInterpolator::onCreate()
{
    return QAndroidJniObject("android/view/animation/BounceInterpolator");
}

QT_END_NAMESPACE
