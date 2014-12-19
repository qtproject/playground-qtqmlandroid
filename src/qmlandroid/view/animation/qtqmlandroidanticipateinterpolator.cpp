#include "qtqmlandroidanticipateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidAnticipateInterpolator::QQmlAndroidAnticipateInterpolator(QObject *parent) :
    QQmlAndroidInterpolator(parent)
{
}

qreal QQmlAndroidAnticipateInterpolator::tension() const
{
    if (m_tension.isNull())
        return 1.0;
    return m_tension.value();
}

void QQmlAndroidAnticipateInterpolator::setTension(qreal tension)
{
    if (m_tension.isNull() || m_tension.value() != tension) {
        m_tension = tension;
        emit tensionChanged();
    }
}

QAndroidJniObject QQmlAndroidAnticipateInterpolator::onCreate()
{
    if (m_tension.isNull())
        return QAndroidJniObject("android/view/animation/AnticipateInterpolator");

    return QAndroidJniObject("android/view/animation/AnticipateInterpolator",
                             "(F)V",
                             m_tension.value());
}

QT_END_NAMESPACE
