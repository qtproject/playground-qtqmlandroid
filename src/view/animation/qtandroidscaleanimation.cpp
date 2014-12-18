#include "qtandroidscaleanimation_p.h"

QT_BEGIN_NAMESPACE

QtAndroidScaleAnimation::QtAndroidScaleAnimation(QObject *parent) :
    QtAndroidAnimation(parent), m_fromX(0), m_fromY(0), m_toX(0), m_toY(0),
    m_pivotX(0), m_pivotY(0), m_pivotXType(ABSOLUTE), m_pivotYType(ABSOLUTE)
{
}

qreal QtAndroidScaleAnimation::fromXScale() const
{
    return m_fromX;
}

void QtAndroidScaleAnimation::setFromXScale(qreal x)
{
    if (m_fromX != x) {
        m_fromX = x;
        emit fromXScaleChanged();
    }
}

qreal QtAndroidScaleAnimation::fromYScale() const
{
    return m_fromY;
}

void QtAndroidScaleAnimation::setFromYScale(qreal y)
{
    if (m_fromY != y) {
        m_fromY = y;
        emit fromYScaleChanged();
    }
}

qreal QtAndroidScaleAnimation::toXScale() const
{
    return m_toX;
}

void QtAndroidScaleAnimation::setToXScale(qreal x)
{
    if (m_toX != x) {
        m_toX = x;
        emit toXScaleChanged();
    }
}

qreal QtAndroidScaleAnimation::toYScale() const
{
    return m_toY;
}

void QtAndroidScaleAnimation::setToYScale(qreal y)
{
    if (m_toY != y) {
        m_toY = y;
        emit toYScaleChanged();
    }
}

qreal QtAndroidScaleAnimation::pivotX() const
{
    return m_pivotX;
}

void QtAndroidScaleAnimation::setPivotX(qreal pivotX)
{
    if (m_pivotX != pivotX) {
        m_pivotX = pivotX;
        emit pivotXChanged();
    }
}

qreal QtAndroidScaleAnimation::pivotY() const
{
    return m_pivotY;
}

void QtAndroidScaleAnimation::setPivotY(qreal pivotY)
{
    if (m_pivotY != pivotY) {
        m_pivotY = pivotY;
        emit pivotYChanged();
    }
}

QtAndroidAnimation::PivotType QtAndroidScaleAnimation::pivotXType() const
{
    return m_pivotXType;
}

void QtAndroidScaleAnimation::setPivotXType(PivotType type)
{
    if (m_pivotXType != type) {
        m_pivotXType = type;
        emit pivotXTypeChanged();
    }
}

QtAndroidAnimation::PivotType QtAndroidScaleAnimation::pivotYType() const
{
    return m_pivotYType;
}

void QtAndroidScaleAnimation::setPivotYType(PivotType type)
{
    if (m_pivotYType != type) {
        m_pivotYType = type;
        emit pivotYTypeChanged();
    }
}

QAndroidJniObject QtAndroidScaleAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/ScaleAnimation",
                             "(FFFFIFIF)V",
                             m_fromX, m_toX, m_fromY, m_toY,
                             m_pivotXType, m_pivotX, m_pivotYType, m_pivotY);
}

void QtAndroidScaleAnimation::onInflate(QAndroidJniObject &instance)
{
    QtAndroidAnimation::onInflate(instance);
}

QT_END_NAMESPACE
