#include "qtqmlandroidanticipateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidAnticipateInterpolator::QtQmlAndroidAnticipateInterpolator(QObject *parent) :
    QtQmlAndroidInterpolator(parent)
{
}

qreal QtQmlAndroidAnticipateInterpolator::tension() const
{
    if (m_tension.isNull())
        return 1.0;
    return m_tension.value();
}

void QtQmlAndroidAnticipateInterpolator::setTension(qreal tension)
{
    if (m_tension.isNull() || m_tension.value() != tension) {
        m_tension = tension;
        emit tensionChanged();
    }
}

QAndroidJniObject QtQmlAndroidAnticipateInterpolator::onCreate()
{
    if (m_tension.isNull())
        return QAndroidJniObject("android/view/animation/AnticipateInterpolator");

    return QAndroidJniObject("android/view/animation/AnticipateInterpolator",
                             "(F)V",
                             m_tension.value());
}

QT_END_NAMESPACE
