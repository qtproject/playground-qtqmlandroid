#include "qtandroiddrawable_p.h"

QtAndroidDrawable::QtAndroidDrawable(QObject *parent) :
    QtAndroidObject(parent)
{
}

QAndroidJniObject QtAndroidDrawable::onCreate()
{
    return QAndroidJniObject("android/graphics/drawable/Drawable");
}

void QtAndroidDrawable::onInflate(QAndroidJniObject &instance)
{
    Q_UNUSED(instance);
}
