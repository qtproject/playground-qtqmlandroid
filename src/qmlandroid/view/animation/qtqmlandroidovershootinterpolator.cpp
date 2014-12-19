#include "qtqmlandroidovershootinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidOvershootInterpolator::QtQmlAndroidOvershootInterpolator(QObject *parent) :
    QtQmlAndroidInterpolator(parent)
{
}

qreal QtQmlAndroidOvershootInterpolator::tension() const
{
    if (m_tension.isNull())
        return 2.0;
    return m_tension.value();
}

void QtQmlAndroidOvershootInterpolator::setTension(qreal tension)
{
    if (m_tension.isNull() || m_tension.value() != tension) {
        m_tension = tension;
        emit tensionChanged();
    }
}

QAndroidJniObject QtQmlAndroidOvershootInterpolator::onCreate()
{
    if (m_tension.isNull())
        return QAndroidJniObject("android/view/animation/OvershootInterpolator");

    return QAndroidJniObject("android/view/animation/OvershootInterpolator",
                             "(F)V",
                             m_tension.value());
}

QT_END_NAMESPACE
