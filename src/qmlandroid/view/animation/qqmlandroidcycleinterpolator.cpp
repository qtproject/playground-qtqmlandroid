#include "qqmlandroidcycleinterpolator_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidCycleInterpolator::QQmlAndroidCycleInterpolator(QObject *parent) :
    QQmlAndroidInterpolator(parent)
{
}

qreal QQmlAndroidCycleInterpolator::cycles() const
{
    if (m_cycles.isNull())
        return 1.0;
    return m_cycles;
}

void QQmlAndroidCycleInterpolator::setCycles(qreal cycles)
{
    if (m_cycles.isNull() || m_cycles != cycles) {
        m_cycles = cycles;
        emit cyclesChanged();
    }
}

QAndroidJniObject QQmlAndroidCycleInterpolator::onCreate()
{
    if (m_cycles.isNull())
        return QAndroidJniObject("android/view/animation/CycleInterpolator");

    return QAndroidJniObject("android/view/animation/CycleInterpolator",
                             "(F)V",
                             m_cycles);
}

QT_END_NAMESPACE
