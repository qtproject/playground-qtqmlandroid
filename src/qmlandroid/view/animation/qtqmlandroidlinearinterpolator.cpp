#include "qtqmlandroidlinearinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidLinearInterpolator::QtQmlAndroidLinearInterpolator(QObject *parent) :
    QtQmlAndroidInterpolator(parent)
{
}

QAndroidJniObject QtQmlAndroidLinearInterpolator::onCreate()
{
    return QAndroidJniObject("android/view/animation/LinearInterpolator");
}

QT_END_NAMESPACE
