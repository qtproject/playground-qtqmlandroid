#include "qtandroiddecelerateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidDecelerateInterpolator::QtAndroidDecelerateInterpolator(QObject *parent) :
    QtAndroidInterpolator(parent)
{
}

QAndroidJniObject QtAndroidDecelerateInterpolator::onCreate()
{
    return QAndroidJniObject("android/view/animation/DecelerateInterpolator");
}

void QtAndroidDecelerateInterpolator::onInflate(QAndroidJniObject &instance)
{
    QtAndroidInterpolator::onInflate(instance);
}

QT_END_NAMESPACE
