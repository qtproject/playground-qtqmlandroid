#include "qqmlandroidscaleanimation_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidScaleAnimation::QQmlAndroidScaleAnimation(QObject *parent) :
    QQmlAndroidAnimation(parent), m_fromX(0), m_fromY(0), m_toX(0), m_toY(0),
    m_pivotX(0), m_pivotY(0), m_pivotXType(ABSOLUTE), m_pivotYType(ABSOLUTE)
{
}

qreal QQmlAndroidScaleAnimation::fromXScale() const
{
    return m_fromX;
}

void QQmlAndroidScaleAnimation::setFromXScale(qreal x)
{
    if (m_fromX != x) {
        m_fromX = x;
        emit fromXScaleChanged();
    }
}

qreal QQmlAndroidScaleAnimation::fromYScale() const
{
    return m_fromY;
}

void QQmlAndroidScaleAnimation::setFromYScale(qreal y)
{
    if (m_fromY != y) {
        m_fromY = y;
        emit fromYScaleChanged();
    }
}

qreal QQmlAndroidScaleAnimation::toXScale() const
{
    return m_toX;
}

void QQmlAndroidScaleAnimation::setToXScale(qreal x)
{
    if (m_toX != x) {
        m_toX = x;
        emit toXScaleChanged();
    }
}

qreal QQmlAndroidScaleAnimation::toYScale() const
{
    return m_toY;
}

void QQmlAndroidScaleAnimation::setToYScale(qreal y)
{
    if (m_toY != y) {
        m_toY = y;
        emit toYScaleChanged();
    }
}

qreal QQmlAndroidScaleAnimation::pivotX() const
{
    return m_pivotX;
}

void QQmlAndroidScaleAnimation::setPivotX(qreal pivotX)
{
    if (m_pivotX != pivotX) {
        m_pivotX = pivotX;
        emit pivotXChanged();
    }
}

qreal QQmlAndroidScaleAnimation::pivotY() const
{
    return m_pivotY;
}

void QQmlAndroidScaleAnimation::setPivotY(qreal pivotY)
{
    if (m_pivotY != pivotY) {
        m_pivotY = pivotY;
        emit pivotYChanged();
    }
}

QQmlAndroidAnimation::Relation QQmlAndroidScaleAnimation::pivotXType() const
{
    return m_pivotXType;
}

void QQmlAndroidScaleAnimation::setPivotXType(Relation type)
{
    if (m_pivotXType != type) {
        m_pivotXType = type;
        emit pivotXTypeChanged();
    }
}

QQmlAndroidAnimation::Relation QQmlAndroidScaleAnimation::pivotYType() const
{
    return m_pivotYType;
}

void QQmlAndroidScaleAnimation::setPivotYType(Relation type)
{
    if (m_pivotYType != type) {
        m_pivotYType = type;
        emit pivotYTypeChanged();
    }
}

QAndroidJniObject QQmlAndroidScaleAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/ScaleAnimation",
                             "(FFFFIFIF)V",
                             m_fromX, m_toX, m_fromY, m_toY,
                             m_pivotXType, m_pivotX, m_pivotYType, m_pivotY);
}

QT_END_NAMESPACE
