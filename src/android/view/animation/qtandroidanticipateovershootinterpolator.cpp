#include "qtandroidanticipateovershootinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidAnticipateOvershootInterpolator::QtAndroidAnticipateOvershootInterpolator(QObject *parent) :
    QtAndroidInterpolator(parent)
{
}

qreal QtAndroidAnticipateOvershootInterpolator::tension() const
{
    if (m_tension.isNull())
        return 1.0;
    return m_tension.value();
}

void QtAndroidAnticipateOvershootInterpolator::setTension(qreal tension)
{
    if (m_tension.isNull() || m_tension.value() != tension) {
        m_tension = tension;
        emit tensionChanged();
    }
}

qreal QtAndroidAnticipateOvershootInterpolator::extraTension() const
{
    if (m_extraTension.isNull())
        return 1.0;
    return m_extraTension.value();
}

void QtAndroidAnticipateOvershootInterpolator::setExtraTension(qreal tension)
{
    if (m_extraTension.isNull() || m_extraTension.value() != tension) {
        m_extraTension = tension;
        emit extraTensionChanged();
    }
}

QAndroidJniObject QtAndroidAnticipateOvershootInterpolator::onCreate()
{
    if (m_tension.isNull() && m_extraTension.isNull())
        return QAndroidJniObject("android/view/animation/AnticipateOvershootInterpolator");

    if (!m_tension.isNull())
        return QAndroidJniObject("android/view/animation/AnticipateOvershootInterpolator",
                                 "(F)V",
                                 m_tension.value());

    return QAndroidJniObject("android/view/animation/AnticipateOvershootInterpolator",
                             "(FF)V",
                             m_tension.value(),
                             m_extraTension.value());
}

QT_END_NAMESPACE
