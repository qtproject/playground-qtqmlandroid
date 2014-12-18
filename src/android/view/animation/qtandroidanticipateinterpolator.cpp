#include "qtandroidanticipateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidAnticipateInterpolator::QtAndroidAnticipateInterpolator(QObject *parent) :
    QtAndroidInterpolator(parent)
{
}

qreal QtAndroidAnticipateInterpolator::tension() const
{
    if (m_tension.isNull())
        return 1.0;
    return m_tension.value();
}

void QtAndroidAnticipateInterpolator::setTension(qreal tension)
{
    if (m_tension.isNull() || m_tension.value() != tension) {
        m_tension = tension;
        emit tensionChanged();
    }
}

QAndroidJniObject QtAndroidAnticipateInterpolator::onCreate()
{
    if (m_tension.isNull())
        return QAndroidJniObject("android/view/animation/AnticipateInterpolator");

    return QAndroidJniObject("android/view/animation/AnticipateInterpolator",
                             "(F)V",
                             m_tension.value());
}

QT_END_NAMESPACE
