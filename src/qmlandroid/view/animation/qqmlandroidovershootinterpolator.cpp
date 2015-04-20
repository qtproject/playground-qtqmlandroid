#include "qqmlandroidovershootinterpolator_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidOvershootInterpolator::QQmlAndroidOvershootInterpolator(QObject *parent) :
    QQmlAndroidInterpolator(parent)
{
}

qreal QQmlAndroidOvershootInterpolator::tension() const
{
    if (m_tension.isNull())
        return 2.0;
    return m_tension;
}

void QQmlAndroidOvershootInterpolator::setTension(qreal tension)
{
    if (m_tension.isNull() || m_tension != tension) {
        m_tension = tension;
        emit tensionChanged();
    }
}

QAndroidJniObject QQmlAndroidOvershootInterpolator::onCreate()
{
    if (m_tension.isNull())
        return QAndroidJniObject("android/view/animation/OvershootInterpolator");

    return QAndroidJniObject("android/view/animation/OvershootInterpolator",
                             "(F)V",
                             m_tension);
}

QT_END_NAMESPACE
