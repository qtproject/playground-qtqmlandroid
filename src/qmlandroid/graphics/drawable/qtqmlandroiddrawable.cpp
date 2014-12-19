#include "qtqmlandroiddrawable_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidDrawable::QQmlAndroidDrawable(QObject *parent) :
    QQmlAndroidObject(parent)
{
}

QAndroidJniObject QQmlAndroidDrawable::onCreate()
{
    return QAndroidJniObject("android/graphics/drawable/Drawable");
}

void QQmlAndroidDrawable::onInflate(QAndroidJniObject &instance)
{
    Q_UNUSED(instance);
}

QT_END_NAMESPACE
