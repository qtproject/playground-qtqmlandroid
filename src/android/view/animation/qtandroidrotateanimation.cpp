#include "qtandroidrotateanimation_p.h"

QT_BEGIN_NAMESPACE

QtAndroidRotateAnimation::QtAndroidRotateAnimation(QObject *parent) :
    QtAndroidAnimation(parent), m_from(0), m_to(0),
    m_pivotX(0), m_pivotY(0), m_pivotXType(ABSOLUTE), m_pivotYType(ABSOLUTE)
{
}

qreal QtAndroidRotateAnimation::fromDegrees() const
{
    return m_from;
}

void QtAndroidRotateAnimation::setFromDegrees(qreal degrees)
{
    if (m_from != degrees) {
        m_from = degrees;
        emit fromDegreesChanged();
    }
}

qreal QtAndroidRotateAnimation::toDegrees() const
{
    return m_to;
}

void QtAndroidRotateAnimation::setToDegrees(qreal degrees)
{
    if (m_to != degrees) {
        m_to = degrees;
        emit toDegreesChanged();
    }
}

qreal QtAndroidRotateAnimation::pivotX() const
{
    return m_pivotX;
}

void QtAndroidRotateAnimation::setPivotX(qreal pivotX)
{
    if (m_pivotX != pivotX) {
        m_pivotX = pivotX;
        emit pivotXChanged();
    }
}

qreal QtAndroidRotateAnimation::pivotY() const
{
    return m_pivotY;
}

void QtAndroidRotateAnimation::setPivotY(qreal pivotY)
{
    if (m_pivotY != pivotY) {
        m_pivotY = pivotY;
        emit pivotYChanged();
    }
}

QtAndroidRotateAnimation::Relation QtAndroidRotateAnimation::pivotXType() const
{
    return m_pivotXType;
}

void QtAndroidRotateAnimation::setPivotXType(Relation type)
{
    if (m_pivotXType != type) {
        m_pivotXType = type;
        emit pivotXTypeChanged();
    }
}

QtAndroidRotateAnimation::Relation QtAndroidRotateAnimation::pivotYType() const
{
    return m_pivotYType;
}

void QtAndroidRotateAnimation::setPivotYType(Relation type)
{
    if (m_pivotYType != type) {
        m_pivotYType = type;
        emit pivotYTypeChanged();
    }
}

QAndroidJniObject QtAndroidRotateAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/RotateAnimation",
                             "(FFIFIF)V",
                             m_from, m_to,
                             m_pivotXType, m_pivotX, m_pivotYType, m_pivotY);
}

QT_END_NAMESPACE
