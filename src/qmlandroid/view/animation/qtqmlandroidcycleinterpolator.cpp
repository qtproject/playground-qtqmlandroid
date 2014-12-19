#include "qtqmlandroidcycleinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidCycleInterpolator::QtQmlAndroidCycleInterpolator(QObject *parent) :
    QtQmlAndroidInterpolator(parent)
{
}

qreal QtQmlAndroidCycleInterpolator::cycles() const
{
    if (m_cycles.isNull())
        return 1.0;
    return m_cycles.value();
}

void QtQmlAndroidCycleInterpolator::setCycles(qreal cycles)
{
    if (m_cycles.isNull() || m_cycles.value() != cycles) {
        m_cycles = cycles;
        emit cyclesChanged();
    }
}

QAndroidJniObject QtQmlAndroidCycleInterpolator::onCreate()
{
    if (m_cycles.isNull())
        return QAndroidJniObject("android/view/animation/CycleInterpolator");

    return QAndroidJniObject("android/view/animation/CycleInterpolator",
                             "(F)V",
                             m_cycles.value());
}

QT_END_NAMESPACE
