#include "qqmlandroidlinearinterpolator_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidLinearInterpolator::QQmlAndroidLinearInterpolator(QObject *parent) :
    QQmlAndroidInterpolator(parent)
{
}

QAndroidJniObject QQmlAndroidLinearInterpolator::onCreate()
{
    return QAndroidJniObject("android/view/animation/LinearInterpolator");
}

QT_END_NAMESPACE
