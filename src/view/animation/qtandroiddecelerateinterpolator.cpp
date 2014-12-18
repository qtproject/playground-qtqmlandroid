#include "qtandroiddecelerateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtAndroidDecelerateInterpolator::QtAndroidDecelerateInterpolator(QObject *parent) :
    QtAndroidInterpolator(parent)
{
}

qreal QtAndroidDecelerateInterpolator::factor() const
{
    if (m_factor.isNull())
        return 1.0;
    return m_factor.value();
}

void QtAndroidDecelerateInterpolator::setFactor(qreal factor)
{
    if (m_factor.isNull() || m_factor.value() != factor) {
        m_factor = factor;
        emit factorChanged();
    }
}

QAndroidJniObject QtAndroidDecelerateInterpolator::onCreate()
{
    if (m_factor.isNull())
        return QAndroidJniObject("android/view/animation/DecelerateInterpolator");

    return QAndroidJniObject("android/view/animation/DecelerateInterpolator",
                             "(F)V",
                             m_factor.value());
}

QT_END_NAMESPACE
