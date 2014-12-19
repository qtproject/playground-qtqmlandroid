#include "qtqmlandroidcolordrawable_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidColorDrawable::QtQmlAndroidColorDrawable(QObject *parent) :
    QtQmlAndroidDrawable(parent), m_color(0)
{
}

QtQmlAndroidColorDrawable::QtQmlAndroidColorDrawable(int color, QObject *parent) :
    QtQmlAndroidDrawable(parent), m_color(color)
{
}

int QtQmlAndroidColorDrawable::color() const
{
    return m_color;
}

void QtQmlAndroidColorDrawable::setColor(int color)
{
    if (m_color != color) {
        m_color = color;
        QtQmlAndroid::callIntMethod(instance(), "setColor", color);
        emit colorChanged();
    }
}

QAndroidJniObject QtQmlAndroidColorDrawable::onCreate()
{
    return QAndroidJniObject("android/graphics/drawable/ColorDrawable");
}

void QtQmlAndroidColorDrawable::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidDrawable::onInflate(instance);

    instance.callMethod<void>("setColor", "(I)V", m_color);
}

QT_END_NAMESPACE
