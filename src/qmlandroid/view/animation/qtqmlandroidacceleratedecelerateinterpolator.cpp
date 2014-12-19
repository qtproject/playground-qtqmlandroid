#include "qtqmlandroidacceleratedecelerateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidAccelerateDecelerateInterpolator::QtQmlAndroidAccelerateDecelerateInterpolator(QObject *parent) :
    QtQmlAndroidInterpolator(parent)
{
}

QAndroidJniObject QtQmlAndroidAccelerateDecelerateInterpolator::onCreate()
{
    return QAndroidJniObject("android/view/animation/AccelerateDecelerateInterpolator");
}

QT_END_NAMESPACE
