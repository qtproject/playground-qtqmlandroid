#include "qtqmlandroidbounceinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidBounceInterpolator::QtQmlAndroidBounceInterpolator(QObject *parent) :
    QtQmlAndroidInterpolator(parent)
{
}

QAndroidJniObject QtQmlAndroidBounceInterpolator::onCreate()
{
    return QAndroidJniObject("android/view/animation/BounceInterpolator");
}

QT_END_NAMESPACE
