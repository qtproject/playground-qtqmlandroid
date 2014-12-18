#include "qtandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidInterpolator::QtAndroidInterpolator(QObject *parent) :
    QtAndroidObject(parent)
{
}

QAndroidJniObject QtAndroidInterpolator::onCreate()
{
    return QAndroidJniObject();
}

QT_END_NAMESPACE
