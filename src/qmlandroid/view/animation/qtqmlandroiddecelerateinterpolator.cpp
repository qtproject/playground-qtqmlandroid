#include "qtqmlandroiddecelerateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidDecelerateInterpolator::QtQmlAndroidDecelerateInterpolator(QObject *parent) :
    QtQmlAndroidInterpolator(parent)
{
}

qreal QtQmlAndroidDecelerateInterpolator::factor() const
{
    if (m_factor.isNull())
        return 1.0;
    return m_factor.value();
}

void QtQmlAndroidDecelerateInterpolator::setFactor(qreal factor)
{
    if (m_factor.isNull() || m_factor.value() != factor) {
        m_factor = factor;
        emit factorChanged();
    }
}

QAndroidJniObject QtQmlAndroidDecelerateInterpolator::onCreate()
{
    if (m_factor.isNull())
        return QAndroidJniObject("android/view/animation/DecelerateInterpolator");

    return QAndroidJniObject("android/view/animation/DecelerateInterpolator",
                             "(F)V",
                             m_factor.value());
}

QT_END_NAMESPACE
