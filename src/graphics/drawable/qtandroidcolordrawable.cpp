#include "qtandroidcolordrawable_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidColorDrawable::QtAndroidColorDrawable(QObject *parent) :
    QtAndroidDrawable(parent), m_color(0)
{
}

QtAndroidColorDrawable::QtAndroidColorDrawable(int color, QObject *parent) :
    QtAndroidDrawable(parent), m_color(color)
{
}

int QtAndroidColorDrawable::color() const
{
    return m_color;
}

void QtAndroidColorDrawable::setColor(int color)
{
    if (m_color != color) {
        m_color = color;
        QtAndroid::callIntMethod(instance(), "setColor", color);
        emit colorChanged();
    }
}

QAndroidJniObject QtAndroidColorDrawable::onCreate()
{
    return QAndroidJniObject("android/graphics/drawable/ColorDrawable");
}

void QtAndroidColorDrawable::onInflate(QAndroidJniObject &instance)
{
    QtAndroidDrawable::onInflate(instance);

    instance.callMethod<void>("setColor", "(I)V", m_color);
}
