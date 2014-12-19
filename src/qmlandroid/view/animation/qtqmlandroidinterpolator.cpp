#include "qtqmlandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidInterpolator::QtQmlAndroidInterpolator(QObject *parent) :
    QtQmlAndroidObject(parent)
{
}

QAndroidJniObject QtQmlAndroidInterpolator::onCreate()
{
    return QAndroidJniObject();
}

QT_END_NAMESPACE
