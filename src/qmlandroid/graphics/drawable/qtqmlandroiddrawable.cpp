#include "qtqmlandroiddrawable_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidDrawable::QtQmlAndroidDrawable(QObject *parent) :
    QtQmlAndroidObject(parent)
{
}

QAndroidJniObject QtQmlAndroidDrawable::onCreate()
{
    return QAndroidJniObject("android/graphics/drawable/Drawable");
}

void QtQmlAndroidDrawable::onInflate(QAndroidJniObject &instance)
{
    Q_UNUSED(instance);
}

QT_END_NAMESPACE
