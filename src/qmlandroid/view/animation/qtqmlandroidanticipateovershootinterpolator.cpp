#include "qtqmlandroidanticipateovershootinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidAnticipateOvershootInterpolator::QtQmlAndroidAnticipateOvershootInterpolator(QObject *parent) :
    QtQmlAndroidInterpolator(parent)
{
}

qreal QtQmlAndroidAnticipateOvershootInterpolator::tension() const
{
    if (m_tension.isNull())
        return 1.0;
    return m_tension.value();
}

void QtQmlAndroidAnticipateOvershootInterpolator::setTension(qreal tension)
{
    if (m_tension.isNull() || m_tension.value() != tension) {
        m_tension = tension;
        emit tensionChanged();
    }
}

qreal QtQmlAndroidAnticipateOvershootInterpolator::extraTension() const
{
    if (m_extraTension.isNull())
        return 1.0;
    return m_extraTension.value();
}

void QtQmlAndroidAnticipateOvershootInterpolator::setExtraTension(qreal tension)
{
    if (m_extraTension.isNull() || m_extraTension.value() != tension) {
        m_extraTension = tension;
        emit extraTensionChanged();
    }
}

QAndroidJniObject QtQmlAndroidAnticipateOvershootInterpolator::onCreate()
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
