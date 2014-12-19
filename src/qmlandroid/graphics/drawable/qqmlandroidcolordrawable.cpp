#include "qqmlandroidcolordrawable_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidColorDrawable::QQmlAndroidColorDrawable(QObject *parent) :
    QQmlAndroidDrawable(parent), m_color(0)
{
}

QQmlAndroidColorDrawable::QQmlAndroidColorDrawable(int color, QObject *parent) :
    QQmlAndroidDrawable(parent), m_color(color)
{
}

int QQmlAndroidColorDrawable::color() const
{
    return m_color;
}

void QQmlAndroidColorDrawable::setColor(int color)
{
    if (m_color != color) {
        m_color = color;
        QtQmlAndroid::callIntMethod(instance(), "setColor", color);
        emit colorChanged();
    }
}

QAndroidJniObject QQmlAndroidColorDrawable::onCreate()
{
    return QAndroidJniObject("android/graphics/drawable/ColorDrawable");
}

void QQmlAndroidColorDrawable::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidDrawable::onInflate(instance);

    instance.callMethod<void>("setColor", "(I)V", m_color);
}

QT_END_NAMESPACE
