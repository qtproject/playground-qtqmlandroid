#include "qqmlandroiddecelerateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidDecelerateInterpolator::QQmlAndroidDecelerateInterpolator(QObject *parent) :
    QQmlAndroidInterpolator(parent)
{
}

qreal QQmlAndroidDecelerateInterpolator::factor() const
{
    if (m_factor.isNull())
        return 1.0;
    return m_factor;
}

void QQmlAndroidDecelerateInterpolator::setFactor(qreal factor)
{
    if (m_factor.isNull() || m_factor != factor) {
        m_factor = factor;
        emit factorChanged();
    }
}

QAndroidJniObject QQmlAndroidDecelerateInterpolator::onCreate()
{
    if (m_factor.isNull())
        return QAndroidJniObject("android/view/animation/DecelerateInterpolator");

    return QAndroidJniObject("android/view/animation/DecelerateInterpolator",
                             "(F)V",
                             m_factor);
}

QT_END_NAMESPACE
