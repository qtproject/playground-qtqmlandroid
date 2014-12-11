#include "qtandroiddrawable_p.h"

QtAndroidDrawable::QtAndroidDrawable(QObject *parent) :
    QtAndroidObject(parent)
{
}

QAndroidJniObject QtAndroidDrawable::construct()
{
    return QAndroidJniObject("android/graphics/drawable/Drawable");
}

void QtAndroidDrawable::inflate()
{
}
