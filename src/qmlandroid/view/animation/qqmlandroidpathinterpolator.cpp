#include "qqmlandroidpathinterpolator_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidPathInterpolator::QQmlAndroidPathInterpolator(QObject *parent) :
    QQmlAndroidInterpolator(parent)
{
}

qreal QQmlAndroidPathInterpolator::controlX() const
{
    if (m_controlX.isNull())
        return 0.0;
    return m_controlX;
}

void QQmlAndroidPathInterpolator::setControlX(qreal x)
{
    if (m_controlX.isNull() || m_controlX != x) {
        m_controlX = x;
        emit controlXChanged();
    }
}

qreal QQmlAndroidPathInterpolator::controlY() const
{
    if (m_controlY.isNull())
        return 0.0;
    return m_controlY;
}

void QQmlAndroidPathInterpolator::setControlY(qreal y)
{
    if (m_controlY.isNull() || m_controlY != y) {
        m_controlY = y;
        emit controlYChanged();
    }
}

qreal QQmlAndroidPathInterpolator::controlX2() const
{
    if (m_controlX2.isNull())
        return 0.0;
    return m_controlX2;
}

void QQmlAndroidPathInterpolator::setControlX2(qreal x)
{
    if (m_controlX2.isNull() || m_controlX2 != x) {
        m_controlX2 = x;
        emit controlX2Changed();
    }
}

qreal QQmlAndroidPathInterpolator::controlY2() const
{
    if (m_controlY2.isNull())
        return 0.0;
    return m_controlY2;
}

void QQmlAndroidPathInterpolator::setControlY2(qreal y)
{
    if (m_controlY2.isNull() || m_controlY2 != y) {
        m_controlY2 = y;
        emit controlY2Changed();
    }
}

QAndroidJniObject QQmlAndroidPathInterpolator::onCreate()
{
    if (!m_controlX.isNull() && !m_controlY.isNull() && !m_controlX2.isNull() && !m_controlY2.isNull())
        return QAndroidJniObject("android/view/animation/PathInterpolator",
                                 "(FFFF)V",
                                 m_controlX,
                                 m_controlY,
                                 m_controlX2,
                                 m_controlY2);

    if (!m_controlX.isNull() && !m_controlY.isNull())
        return QAndroidJniObject("android/view/animation/PathInterpolator",
                                 "(FF)V",
                                 m_controlX,
                                 m_controlY);

    return QAndroidJniObject();
}

QT_END_NAMESPACE
