#include "qtandroidaccelerateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidAccelerateInterpolator::QtAndroidAccelerateInterpolator(QObject *parent) :
    QtAndroidInterpolator(parent)
{
}

qreal QtAndroidAccelerateInterpolator::factor() const
{
    if (m_factor.isNull())
        return 1.0;
    return m_factor.value();
}

void QtAndroidAccelerateInterpolator::setFactor(qreal factor)
{
    if (m_factor.isNull() || m_factor.value() != factor) {
        m_factor = factor;
        emit factorChanged();
    }
}

QAndroidJniObject QtAndroidAccelerateInterpolator::onCreate()
{
    if (m_factor.isNull())
        return QAndroidJniObject("android/view/animation/AccelerateInterpolator");

    return QAndroidJniObject("android/view/animation/AccelerateInterpolator",
                             "(F)V",
                             m_factor.value());
}

QT_END_NAMESPACE
