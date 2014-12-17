#include "qtandroiddrawable_p.h"

QT_BEGIN_NAMESPACE

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

QT_END_NAMESPACE
