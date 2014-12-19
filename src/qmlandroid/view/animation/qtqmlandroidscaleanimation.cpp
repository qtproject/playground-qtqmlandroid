#include "qtqmlandroidscaleanimation_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidScaleAnimation::QtQmlAndroidScaleAnimation(QObject *parent) :
    QtQmlAndroidAnimation(parent), m_fromX(0), m_fromY(0), m_toX(0), m_toY(0),
    m_pivotX(0), m_pivotY(0), m_pivotXType(ABSOLUTE), m_pivotYType(ABSOLUTE)
{
}

qreal QtQmlAndroidScaleAnimation::fromXScale() const
{
    return m_fromX;
}

void QtQmlAndroidScaleAnimation::setFromXScale(qreal x)
{
    if (m_fromX != x) {
        m_fromX = x;
        emit fromXScaleChanged();
    }
}

qreal QtQmlAndroidScaleAnimation::fromYScale() const
{
    return m_fromY;
}

void QtQmlAndroidScaleAnimation::setFromYScale(qreal y)
{
    if (m_fromY != y) {
        m_fromY = y;
        emit fromYScaleChanged();
    }
}

qreal QtQmlAndroidScaleAnimation::toXScale() const
{
    return m_toX;
}

void QtQmlAndroidScaleAnimation::setToXScale(qreal x)
{
    if (m_toX != x) {
        m_toX = x;
        emit toXScaleChanged();
    }
}

qreal QtQmlAndroidScaleAnimation::toYScale() const
{
    return m_toY;
}

void QtQmlAndroidScaleAnimation::setToYScale(qreal y)
{
    if (m_toY != y) {
        m_toY = y;
        emit toYScaleChanged();
    }
}

qreal QtQmlAndroidScaleAnimation::pivotX() const
{
    return m_pivotX;
}

void QtQmlAndroidScaleAnimation::setPivotX(qreal pivotX)
{
    if (m_pivotX != pivotX) {
        m_pivotX = pivotX;
        emit pivotXChanged();
    }
}

qreal QtQmlAndroidScaleAnimation::pivotY() const
{
    return m_pivotY;
}

void QtQmlAndroidScaleAnimation::setPivotY(qreal pivotY)
{
    if (m_pivotY != pivotY) {
        m_pivotY = pivotY;
        emit pivotYChanged();
    }
}

QtQmlAndroidAnimation::Relation QtQmlAndroidScaleAnimation::pivotXType() const
{
    return m_pivotXType;
}

void QtQmlAndroidScaleAnimation::setPivotXType(Relation type)
{
    if (m_pivotXType != type) {
        m_pivotXType = type;
        emit pivotXTypeChanged();
    }
}

QtQmlAndroidAnimation::Relation QtQmlAndroidScaleAnimation::pivotYType() const
{
    return m_pivotYType;
}

void QtQmlAndroidScaleAnimation::setPivotYType(Relation type)
{
    if (m_pivotYType != type) {
        m_pivotYType = type;
        emit pivotYTypeChanged();
    }
}

QAndroidJniObject QtQmlAndroidScaleAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/ScaleAnimation",
                             "(FFFFIFIF)V",
                             m_fromX, m_toX, m_fromY, m_toY,
                             m_pivotXType, m_pivotX, m_pivotYType, m_pivotY);
}

QT_END_NAMESPACE
